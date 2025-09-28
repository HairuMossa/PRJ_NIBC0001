/**
 * @file adc_controller.h
 * @author Hairu Mossa
 * @brief ADC controller interface. Provides functions to read various analog signals.
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef ADC_CONTROLLER_H
#define ADC_CONTROLLER_H

#include <stdbool.h>

/**
 * @brief Get the output voltage in volts
 * 
 * @return float 
 */
float adc_controller_get_output_voltage(void);

/**
 * @brief Get the output current in amps
 * 
 * @return float 
 */
float adc_controller_get_output_current(void);

/**
 * @brief Get the input voltage in volts
 * 
 * @return float 
 */
float adc_controller_get_input_voltage(void);

/**
 * @brief Get the temperature in degree centigrade
 * 
 * @return float 
 */
float adc_controller_get_temperature(void);

/**
 * @brief Initialize the ADC controller
 * 
 */
void adc_controller_init(void);


#endif