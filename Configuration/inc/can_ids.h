/**
 * @file can_ids.h
 * @author Hairu Mossa
 * @brief CAN IDs and on-wire payload definitions
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CAN_IDS_H
#define CAN_IDS_H
#include <stdint.h>

// CAN Message ID
#define CAN_ID_TELEMETRY            0x555u

// ---- On-wire payload (single classic CAN frame, DLC=8) ----
// Byte layout (little-endian / Intel):
// 0: Telemetry_InputVoltage   (u8, V, 0.25 V/LSB, 0..60 V)
// 1: Telemetry_InputCurrent   (u8, A, 0.10 A/LSB, 0..20 A)
// 2: Telemetry_OutputVoltage  (u8, V, 0.20 V/LSB, 0..30 V)
// 3: Telemetry_OutputCurrent  (u8, A, 0.05 A/LSB, 0..12 A)
// 4: Telemetry_Temperature    (s8, °C, 1 °C/LSB, -40..125 °C)
// 5: Telemetry_StatusFlags    (u8, [1:0]=SystemState, [5:2]=ErrorFlags, [7:6]=0)
// 6: Telemetry_Reserved1      (u8, 0)
// 7: Telemetry_Reserved2      (u8, 0)
typedef struct __attribute__((packed)) {
    uint8_t Telemetry_InputVoltage;
    uint8_t Telemetry_InputCurrent;
    uint8_t Telemetry_OutputVoltage;
    uint8_t Telemetry_OutputCurrent;
    int8_t  Telemetry_Temperature;
    uint8_t Telemetry_StatusFlags;
    uint8_t Telemetry_Reserved1;
    uint8_t Telemetry_Reserved2;
} telemetry_t;

#endif