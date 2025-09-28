/**
 * @file if_pwm.h
 * @author Hairu Mossa
 * @brief  This is the header file for the PWM interface module.
 * It provides functions to initialize and control PWM signals for the Buck Converter.
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef IF_PWM_H
#define IF_PWM_H

#include "stm32f1xx_hal.h"
#include "control_params.h"
#include "main.h"
/**
 * @brief Initialize the PWM hardware (TIM1 Channel 1) for controlling the Buck Converter.
 * 
 */
void if_pwm_init(void);

/**
 * @brief Set the PWM duty cycle for the Buck Converter.
 * 
 * @param duty_cycle Duty cycle as a float between 0.0 (0%) and 1.0 (100%).
 */
void if_pwm_set_duty_cycle(float duty_cycle);

/**
 * @brief Enable the PWM output.
 * 
 */
void if_pwm_enable(void);

/**
 * @brief Disable the PWM output.
 * 
 */
void if_pwm_disable(void);

#endif