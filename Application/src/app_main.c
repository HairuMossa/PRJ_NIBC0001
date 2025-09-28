#include "app_main.h"
#include "app_control.h"
#include "app_telemetry.h"
#include "if_timer.h"
#include "error_controller.h"
#include "adc_controller.h"
#include "app_state.h"
#include "pwm_controller.h"

void app_main_init(void) {
    // Initialize all modules
	error_controller_init(); 
	adc_controller_init();
    app_control_init();
    app_telemetry_init();
    timer_controller_init();
    
    // Start timers
    timer_controller_start();
}

void app_main_run(void) {
    // Main superloop
    while (1) {
        // 10 khz Control Loop
        if (if_timer_check_control_flag() == 1) {

        	if_timer_clear_control_flag(); //clears the callback flag in the timer module
            app_run_State_machine(); // Run state machine
            app_control_run_10kHz(); // call control loop
        }
        
        // 10 hz Telemetry
        if (if_timer_check_telemetry_flag() == 1) {

        	if_timer_clear_telemetry_flag(); //clears the callback flag in the timer module
            app_telemetry_send(); // send telemetry data over CAN
        }
        
    }
}
