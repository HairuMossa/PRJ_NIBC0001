/**
 * @file app_main.h
 * @author Hairu Mossa
 * @brief  This is the header file for the main application module.
 * It declares the initialization and main loop functions. 
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef APP_MAIN_H
#define APP_MAIN_H

/**
 * @brief Initialize all application modules and start timers.
 * 
 */
void app_main_init(void);

/**
 * @brief Main application loop that schedules PID control and telemetry tasks.
 * 
 */
void app_main_run(void);

#endif