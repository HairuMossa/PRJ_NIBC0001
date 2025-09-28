#include "if_timer.h"
#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim2;  // Control loop timer (10 kHz)
extern TIM_HandleTypeDef htim3;  // Telemetry timer (10 Hz)

static volatile bool control_flag = false;
static volatile bool telemetry_flag = false;

void if_timer_init(void) {
    // Configuration done by CubeMX
}

void if_timer_start(void) {
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim3);
}

bool if_timer_check_control_flag(void) {
    return control_flag;
}

bool if_timer_check_telemetry_flag(void) {
    return telemetry_flag;
}


void if_timer_clear_telemetry_flag(void) {`
    telemetry_flag = false;
}

void if_timer_clear_control_flag(void) {
    control_flag = false;
}

// Timer interrupt callbacks
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        control_flag = true;  // 10 kHz control loop
    }
    else if (htim->Instance == TIM3) {
        telemetry_flag = true;  // 10 Hz telemetry
    }
}