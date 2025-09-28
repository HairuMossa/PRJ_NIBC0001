/**
 * @file if_can.h
 * @author Hairu Mossa
 * @brief  This is the header file for the CAN interface module.
 * It provides functions to initialize the CAN peripheral and send telemetry data.
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef IF_CAN_H
#define IF_CAN_H

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "main.h"

/**
 * @brief Initialize the CAN peripheral.
 * 
 */
void if_can_init(void);

/**
 * @brief Send telemetry data over CAN bus.
 * 
 * @param id CAN message ID
 * @param data Pointer to data buffer (8 bytes)
 * @param len Length of data (should be 8 for classic CAN)
 */
void if_can_send_telemetry(uint32_t id, const uint8_t* data, uint8_t len);

#endif