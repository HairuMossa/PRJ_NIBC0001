/**
 * @file app_telemetry.h
 * @author Hairu Mossa
 * @brief  This is the header file for the application telemetry module that runs at 10 Hz.
 * It handles sending system telemetry data over CAN bus.
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef APP_TELEMETRY_H
#define APP_TELEMETRY_H

/**
 * @brief Initialize the CAN interface for telemetry transmission.
 * 
 */
void app_telemetry_init(void);

/**
 * @brief Collect system telemetry data and send it over CAN bus.
 * This function runs at 10 Hz.
 * 
 */
void app_telemetry_send(void);

#endif