/**
 * @file pid_controller.h
 * @author Hairu Mossa
 * @brief PID controller interface
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

/**
 * @brief PID controller parameters and state
 * 
 */
typedef struct {
    float kp, ki, kd;
    float integral;
    float prev_error;
    float output_min;
    float output_max;
} pid_parameters_t;

/**
 * @brief Initialize the PID controller
 * 
 * @param pid Pointer to PID parameters structure
 */
void pid_controller_init(pid_parameters_t* pid);

/**
 * @brief Update the PID controller with a new measurement
 * 
 * @param pid Pointer to PID parameters structure
 * @param setpoint Desired setpoint
 * @param measurement Current measurement
 * @param dt Time step in seconds
 * @return float Control output
 */
float pid_controller_update(pid_parameters_t* pid, float setpoint, float measurement, float dt);

/**
 * @brief Reset the PID controller state (integral and previous error)
 * 
 * @param pid Pointer to PID parameters structure
 */
void pid_controller_reset(pid_parameters_t* pid);

#endif