#include "pid_controller.h"
#include "control_params.h"

void pid_controller_init(pid_parameters_t* pid) {
    pid->kp = PID_KP;
    pid->ki = PID_KI;
    pid->kd = PID_KD;
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
    pid->output_min = PID_OUTPUT_MIN;
    pid->output_max = PID_OUTPUT_MAX;
}

float pid_controller_update(pid_parameters_t* pid, float setpoint, float measurement, float dt) {
    float error = setpoint - measurement;
    
    //! Proportional term
    float proportional = pid->kp * error;
    
    //! Integral term
    pid->integral += error * dt;
    float integral = pid->ki * pid->integral;
    
    //! Derivative term
    float derivative = pid->kd * (error - pid->prev_error) / dt;
    pid->prev_error = error;
    
    //! Calculate output
    float output = proportional + integral + derivative;
    
    //! Clamp output.
    if (output > pid->output_max) output = pid->output_max;
    if (output < pid->output_min) output = pid->output_min;
    
    return output;
}

void pid_controller_reset(pid_parameters_t* pid) {
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
}