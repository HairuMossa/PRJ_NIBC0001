# PRJ_NIBC0001 – Non Isolated Buck Converter Embedded Sofware

I decided to use **layered software architecture** to abstruct the hardware from the software. 

---

## Layered Architecture Overview

The firmware is divided into distinct **layers**, each with specific responsibilities and dependencies.  

- Upper layers (Application) focus on **high-level logic**.  
- Lower layers (Interface, System) handle **hardware interactions**.  
- Dependencies always flow **downward**:  
  `Application → Controller → Interface → System`


**High-Level Software Architecture**  

<img width="492" height="534" alt="image" src="https://github.com/user-attachments/assets/3ae4aedc-5ef5-4101-9493-ca7db26d0b5a" />


---

## Layer Descriptions

### 1. Application Layer
**Purpose**: Implements the system’s high-level logic and state machines.  
**Responsibilities**:
- Defines operational states (Idle, Running, Error, etc.)  
- Executes the control loop at **10 kHz**  
- Triggers telemetry updates at **10 Hz**  

### 2. Controller Layer
**Purpose**: Encapsulates control algorithms and logic for system behavior.  
**Responsibilities**:
- Implements the **PID controller**  
- Prepares telemetry data  
- Decides when/how to call Interface functions  

### 3. Interface Layer
**Purpose**: Provides hardware-agnostic access to peripherals.  
**Responsibilities**:
- Abstracts **ADC, PWM, CAN, Timers, GPIO**  
- Defines clean APIs for Controller layer  
- Ensures portability for higher layers  

### 4. Lower Layers (System / HAL)
**Purpose**: STM32Cube HAL and low-level hardware initialization.  
**Responsibilities**:
- CubeMX-generated init code  
- Hardware setup (clocks, pins, peripherals)  
- Provides base functions for Interface layer  

For detailed architecture, see:  
📄 [SWE2_Software_Architecture.pdf](https://github.com/HairuMossa/PRJ_NIBC0001/blob/master/Documentation/SWE2_Software_Architecture.pdf)

---

## Hardware Architecture

The overall hardware architecture is centered around the **STM32F103 MCU** (used for demonstration; not tested on actual hardware).  

**Hardware Block Diagram**  

<img width="1743" height="711" alt="image" src="https://github.com/user-attachments/assets/1d2b9726-473e-404c-8151-bb03292042b8" />


---

## Data & Control Flow

- **Timer Interrupts** (10 kHz / 10 Hz) trigger Application logic.  
- **Application Layer** calls into Controller Layer (e.g., run PID).  
- **Controller Layer** requests data from Interface Layer (e.g., ADC voltage).  
- **Interface Layer** interacts with HAL/System Layer.  

### Timing Goals
- Control Loop: **10 kHz** (100 µs)  
- PWM Carrier: **20 kHz** (50 µs)  
- Telemetry: **10 Hz** (100 ms)  

Timers used: **TIM1, TIM2, TIM3**.  

---

## Requirements & Traceability

A basic requirements specification is provided. Each requirement is uniquely identified and linked to its parent requirement in the **traceability section**.  

- 📄 [System Requirements Specification (SYS2)](https://github.com/HairuMossa/PRJ_NIBC0001/blob/master/Documentation/SYS2_System_Requirement_Specification.pdf)  
- 📄 [Software Requirements Specification (SWE1)](https://github.com/HairuMossa/PRJ_NIBC0001/blob/master/Documentation/SWE1_Software_Requirement_Specification.pdf)  

---

## Documentation

The software is documented with **Doxygen**.

### How to View Doxygen Docs
1. Clone this repository.  
2. Open `Documentation/html/index.html` in a web browser.  

---

## Repository Structure

<img width="822" height="210" alt="image" src="https://github.com/user-attachments/assets/628a42e1-81a1-4b2a-b462-08282f5da90f" />


---

## Status

Firmware compiles successfully.  
Hardware testing not performed.  

---

## Versioning & Commit Rules I followed

- **Commit Rules**: [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)  
- **Versioning**: [Semantic Versioning](https://semver.org/) 

---
