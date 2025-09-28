/**
 * @file if_timer.h
 * @author Hairu Mossa
 * @brief This is the header file for the timer interface module.
 * It provides functions to initialize and manage timers for scheduling tasks.
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef IF_TIMER_H
#define IF_TIMER_H

#include <stdbool.h>
#include "stm32f1xx_hal.h"
#include "main.h"

/**
 * @brief Initialize the hardware timers for control loop and telemetry scheduling.
 * 
 */
void if_timer_init(void);

/**
 * @brief Start the timers to begin generating periodic interrupts.
 * 
 */
void if_timer_start(void);

/**
 * @brief Check if the 10 kHz control loop flag is set.
 * 
 * @return true if the control loop flag is set, false otherwise.
 */
bool if_timer_check_control_flag(void);

/**
 * @brief Check if the 10 Hz telemetry flag is set.
 * 
 * @return true if the telemetry flag is set, false otherwise.
 */
bool if_timer_check_telemetry_flag(void);

/**
 * @brief Clear the 10 kHz control loop flag after it has been handled.
 * 
 */
void if_timer_clear_control_flag(void);

/**
 * @brief Clear the 10 Hz telemetry flag after it has been handled.
 * 
 */
void if_timer_clear_telemetry_flag(void);

#endif