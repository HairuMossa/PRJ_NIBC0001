/**
 * @file app_state.h
 * @author Hairu Mossa
 * @brief  This is the header file for the application state management module.
 * It defines the system states and declares functions to get and manage the current state.
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef APP_STATE_H
#define APP_STATE_H

/**
 * @brief Enumeration of possible system states.
 * 
 */
typedef enum {
    SYSTEM_STATE_IDLE = 0,
    SYSTEM_STATE_RUNNING,
    SYSTEM_STATE_ERROR
} system_state_e;

/**
 * @brief Get the current system state.
 * 
 * @return Current system state as a value of system_state_e.
 */
system_state_e app_State_get_system_tate(void);

/**
 * @brief Run the state machine to handle state transitions and actions.
 * 
 */
void app_run_State_machine(void);

#endif
