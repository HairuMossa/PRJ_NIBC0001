#include "pwm_controller.h"


void pwm_controller_init(void) {
	if_pwm_init(); // Initialize the PWM hardware
}

void pwm_controller_set_duty(float duty) {
	if_pwm_set_duty_cycle(duty); // Set the PWM duty cycle
}

void pwm_controller_disable_pwm(void) {
	if_pwm_disable(); // Disable the PWM output
}

// I dind't want to put this in a separate file just for CAN init and telemetry sending
void can_controller_init(void){
    if_can_init(); // Initialize the CAN hardware
}

void can_controller_send_telemetry(uint32_t id, const uint8_t* data, uint8_t len) {
    if_can_send_telemetry(id, data, len); // Send telemetry data over CAN
}


void timer_controller_init(void){
    if_timer_init(); // Initialize the timer hardware
}
void timer_controller_start(void){
    if_timer_start(); // Start the timer
}