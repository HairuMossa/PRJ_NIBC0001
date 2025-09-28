/**
 * @file control_params.h
 * @author Hairu Mossa
 * @brief Control parameters for the PID controller and system limits.
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CONTROL_PARAMS_H
#define CONTROL_PARAMS_H

// Control Parameters
#define CONTROL_LOOP_FREQ           10000.0f   // 10 kHz
#define CONTROL_LOOP_DT             (1.0f / CONTROL_LOOP_FREQ)
#define TELEMETRY_FREQ              10.0f      // 10 Hz (100ms)

// PID Parameters
#define PID_KP                      0.1f
#define PID_KI                      5.0f
#define PID_KD                      0.001f
#define PID_OUTPUT_MIN              0.0f       // 0% min duty
#define PID_OUTPUT_MAX              0.95f      // 95% max duty

// System Limits
#define TARGET_VOUT                 24.0f      // Target output voltage
#define MAX_OUTPUT_CURRENT          10.0f      // Overcurrent threshold
#define OVERTEMP_THRESHOLD          80.0f      // in degrees Celsius

// ADC Configuration
#define ADC_VREF                    3.3f       // Reference voltage
#define ADC_MAX                     4095.0f    // 12-bit ADC max value
#define ADC_TO_VOLTS(adc_val)       ((adc_val) * ADC_VREF / ADC_MAX)
#define ADC_TO_AMPERE(adc_val)       ((adc_val) * ADC_VREF / ADC_MAX)

#endif