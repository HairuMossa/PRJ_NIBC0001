#include "app_control.h"
#include "pid_controller.h"
#include "adc_controller.h"
#include "error_controller.h"
#include "pwm_controller.h"
#include "control_params.h"
#include "error_controller.h"

/**
 * @brief PID controller instance
 * 
 */
static pid_parameters_t pid;


void app_control_init(void) {
	pid_controller_init(&pid); // initialize PID with parameters from control_params.h
	pwm_controller_init(); // Initialize PWM through interface layer
}

void app_control_run_10kHz(void) {
    // Read ADC messurements 
    float v_out = adc_controller_get_output_voltage();
    float i_out = adc_controller_get_output_current();
    
    // Overcurrent protection (highest priority)
    if (i_out > MAX_OUTPUT_CURRENT) {
    	error_controller_set_error(ERROR_OVERCURRENT);
        
        // Reduce duty cycle by 5% for safety
        static float current_duty = 0.0f;
        current_duty -= 0.05f;
        if (current_duty < 0.0f) {
            current_duty = 0.0f;
        }

        pwm_controller_set_duty(current_duty);
        return;
    }
    
    // Clear overcurrent error if condition is normal
    if (i_out < MAX_OUTPUT_CURRENT * 0.9f) {
    	error_controller_clear_error(ERROR_OVERCURRENT);
    }
    
    // Normal PID voltage control
    float duty_cycle = pid_controller_update(&pid, TARGET_VOUT, v_out, CONTROL_LOOP_DT);
    pwm_controller_set_duty(duty_cycle); // Set new duty cycle
}
