/**
 * @file if_adc.h
 * @author Hairu Mossa
 * @brief ADC hardware interface
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef IF_ADC_H
#define IF_ADC_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32f1xx_hal.h"
#include "main.h"

#define ADC_NUM_CHANNELS 4 // Number of ADC channels used

/**
 * @brief ADC channels enumeration
 * 
 */
typedef enum {
    ADC_CH_OUTPUT_VOLTAGE = 0,
    ADC_CH_OUTPUT_CURRENT = 1,
    ADC_CH_INPUT_VOLTAGE = 2,
    ADC_CH_TEMPERATURE = 3
} adc_channel_e;

/**
 * @brief Initialize the ADC hardware
 * 
 */
void if_adc_init(void);

/**
 * @brief Get the raw ADC value for the specified channel
 * 
 * @param channel ADC channel to read
 * @return uint16_t Raw ADC value (0 to 4095 12-bit ADC range)
 */
uint16_t if_adc_get_raw_value(adc_channel_e channel);

#endif