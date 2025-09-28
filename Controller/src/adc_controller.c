#include "adc_controller.h"
#include "if_adc.h"
#include "control_params.h"

void adc_controller_init(void) {
    if_adc_init(); // Initialize the ADC hardware
}

float adc_controller_get_output_voltage(void) {
    uint16_t raw = if_adc_get_raw_value(ADC_CH_OUTPUT_VOLTAGE); // Read raw ADC value
    return ADC_TO_VOLTS(raw); // Convert to volts using defined macro
}

float adc_controller_get_output_current(void) {
    uint16_t raw = if_adc_get_raw_value(ADC_CH_OUTPUT_CURRENT); // Read raw ADC value
    return ADC_TO_AMPERE(raw); // Convert to amps using defined macro
}

float adc_controller_get_input_voltage(void) {
    uint16_t raw = if_adc_get_raw_value(ADC_CH_INPUT_VOLTAGE); // Read raw ADC value
    return ADC_TO_VOLTS(raw); // Convert to volts using defined macro
}

float adc_controller_get_temperature(void) {
    uint16_t raw = if_adc_get_raw_value(ADC_CH_TEMPERATURE); // Read raw ADC value
    // Simple conversion
    return (ADC_TO_VOLTS(raw) * 100.0f);  // Rough conversion to degree Centigrade
}

