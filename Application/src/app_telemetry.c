#include "app_telemetry.h"
#include "adc_controller.h"
#include "error_controller.h"
#include "pwm_controller.h"
#include "app_state.h"
#include "can_ids.h"
#include <math.h>
#include <string.h>


//! helpers for quantization and packing
static inline uint8_t q_u8_step(float x, float min_v, float max_v, float step)
{
    if (x < min_v) x = min_v;
    if (x > max_v) x = max_v;
    float enc = roundf(x / step);
    if (enc < 0.0f)   enc = 0.0f;
    if (enc > 255.0f) enc = 255.0f;
    return (uint8_t)enc;
}

static inline int8_t clamp_temp_s8(float tC)
{
    if (tC < -40.0f) tC = -40.0f;
    if (tC > 125.0f) tC = 125.0f;
    return (int8_t)lroundf(tC);
}

//! StatusFlags byte: [5:2]=ErrorFlags (bits 0..3), [1:0]=SystemState (0..3)
static inline uint8_t make_status_flags(system_state_e st, uint8_t errMask)
{
    uint8_t st2  = ((uint8_t)st) & 0x03u;
    uint8_t err4 = ((uint8_t)errMask) & 0x0Fu;
    return (uint8_t)((err4 << 2) | st2);
}


void app_telemetry_init(void) {
	can_controller_init();
}

void app_telemetry_send(void) {
    telemetry_t tx = {0};

    //! Read measurements (assumes these getters exist; add your own if names differ)
    float v_in  = adc_controller_get_input_voltage();   //! V (0..60)
    float i_in  = 10;   //! range unknown, I will do it later
    float v_out = adc_controller_get_output_voltage();  //! V (0..30)
    float i_out = adc_controller_get_output_current();  //! A (0..12)
    float temp  = adc_controller_get_temperature();    //! degree centigrade (-40..125)

    //! Quantize to on-wire resolution
    tx.Telemetry_InputVoltage  = q_u8_step(v_in,  0.0f, 60.0f, 0.25f); // 0.25 V/LSB
    tx.Telemetry_InputCurrent  = q_u8_step(i_in,  0.0f, 20.0f, 0.10f); // 0.10 A/LSB
    tx.Telemetry_OutputVoltage = q_u8_step(v_out, 0.0f, 30.0f, 0.20f); // 0.20 V/LSB
    tx.Telemetry_OutputCurrent = q_u8_step(i_out, 0.0f, 12.0f, 0.05f); // 0.05 A/LSB
    tx.Telemetry_Temperature   = clamp_temp_s8(temp);

    //! System state
    system_state_e state = app_State_get_system_tate();

    //! Error flags from global error_controller
    error_flags_e errors = (uint8_t)error_controller_gete_errors(); // matches ErrorFlags_t bit mask

    //! Pack status/flags
    tx.Telemetry_StatusFlags = make_status_flags(state, errors);

    //! Reserved bytes = 0
    tx.Telemetry_Reserved1 = 0u;
    tx.Telemetry_Reserved2 = 0u;

    //! Transmit 
    can_controller_send_telemetry(CAN_ID_TELEMETRY, (const uint8_t *)&tx, sizeof(tx));
}
