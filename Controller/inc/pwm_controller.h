/**
 * @file pwm_controller.h
 * @author Hairu Mossa
 * @brief PWM controller interface. includes CAN and Timer controller functions.
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef PWM_CONTROLLER_H
#define PWM_CONTROLLER_H

#include "if_pwm.h"
#include "if_can.h"

/**
 * @brief Initialize the PWM controller
 * 
 */
void pwm_controller_init(void);

/**
 * @brief Set the PWM duty cycle
 * 
 * @param duty Duty cycle (0.0 to 1.0)
 */
void pwm_controller_set_duty(float duty);

/**
 * @brief Disable the PWM output
 * 
 */
void pwm_controller_disable_pwm(void);


// I dind't want to put this in a separate file just for CAN init and telemetry sending
/**
 * @brief Initialize the CAN controller
 * 
 */
void can_controller_init(void);

/**
 * @brief Send telemetry data over CAN
 * 
 * @param id CAN message ID
 * @param data Pointer to data buffer (8 bytes)
 * @param len Length of data
 */
void can_controller_send_telemetry(uint32_t id, const uint8_t* data, uint8_t len);


// Timer controller functions for timer initialization and start
/**
 * @brief Initialize the timer controller
 * 
 */
void timer_controller_init(void);

/**
 * @brief Start the timer
 * 
 */
void timer_controller_start(void);

#endif