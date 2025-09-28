#include "app_state.h"
#include "can_ids.h"
#include "error_controller.h"
#include "pwm_controller.h"
#include "if_can.h"


/**
 * @brief initial state of the system
 * 
 */
static system_state_e s_state = SYSTEM_STATE_IDLE;


system_state_e app_State_get_system_tate(void){
    return s_state;
}

void app_run_State_machine(void)
{
    // Read current error flags
	error_flags_e app_errors = error_controller_gete_errors();
    const uint32_t FATAL_MASK = (ERROR_OVERTEMP | ERROR_ADC_FAILURE);

    switch (s_state) {
    case SYSTEM_STATE_IDLE:
        // Go RUNNING if there are no fatal errors (NONE or only OVERCURRENT)
        if ((app_errors & FATAL_MASK) == 0u) {
            s_state = SYSTEM_STATE_RUNNING;
        }
        break;

    case SYSTEM_STATE_RUNNING:
        // Any fatal error -> ERROR
        if ((app_errors & FATAL_MASK) != 0u) {
            pwm_controller_disable_pwm();
            s_state = SYSTEM_STATE_ERROR;
        }
        // else stay RUNNING even if OVERCURRENT is set
        break;

    case SYSTEM_STATE_ERROR:
        // manual reset required (not implemented)
        break;
    }
}
