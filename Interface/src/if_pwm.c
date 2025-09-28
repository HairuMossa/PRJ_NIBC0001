#include "if_pwm.h"


extern TIM_HandleTypeDef htim1;  // PWM Timer from CubeMX

void if_pwm_init(void) {
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void if_pwm_set_duty_cycle(float duty_cycle) {
    // Clamp to safe limits
    if (duty_cycle < 0.0f) {
        duty_cycle = 0.0f;
    }

    if (duty_cycle > PID_OUTPUT_MAX) { 
        duty_cycle = PID_OUTPUT_MAX;
    }
    
    uint32_t arr = __HAL_TIM_GET_AUTORELOAD(&htim1);
    uint32_t ccr = (uint32_t)(duty_cycle * arr);
    
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, ccr);
}

void if_pwm_enable(void) {
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void if_pwm_disable(void) {
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}