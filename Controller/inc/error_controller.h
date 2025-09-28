/**
 * @file error_controller.h
 * @author Hairu Mossa
 * @brief Error controller interface. Manages system error flags.
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ERROR_CONTROLLER_H
#define ERROR_CONTROLLER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Error flags bitmask
 * 
 */
typedef enum {
    ERROR_NONE            = 0,
    ERROR_OVERCURRENT     = 1 << 0,
    ERROR_OVERTEMP        = 1 << 1,
    ERROR_ADC_FAILURE     = 1 << 2
} error_flags_e;

/**
 * @brief Initialize the error controller
 * 
 */
void error_controller_init(void);

/**
 * @brief Set an error flag
 * 
 * @param error Error flag to set (bitmask)
 */
void error_controller_set_error(error_flags_e error);

/**
 * @brief Clear an error flag
 * 
 * @param error Error flag to clear (bitmask)
 */
void error_controller_clear_error(error_flags_e error);

/**
 * @brief Get the current error flags
 * 
 * @return error_flags_e Current error flags (bitmask)
 */
error_flags_e error_controller_gete_errors(void);

#endif