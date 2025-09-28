/**
 * @file app_control.h
 * @author Hairu Mossa
 * @brief This is the header file for the application control module that runs at 10 kHz.
 * It handles the PID control loop for voltage regulation and overcurrent protection.
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef APP_CONTROL_H
#define APP_CONTROL_H

/**
 * @brief Initialize the PID parameters(can be configured in control_params.h file) and PWM throught the interface layer.
 * 
 */
void app_control_init(void);

/**
 * @brief this function runs at 10 kHz to perform the PID control loop. 
 * It reads the output voltage and current,
 * 
 */
void app_control_run_10kHz(void);

#endif