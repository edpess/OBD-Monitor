# OBD-Monitor
Tools for interfacing with vehicle engine control units using the OBD-II protocol.


## STATUS: Experimental.

## 1. Introduction

 The On-Board Diagnostics II (OBD-II) standard is a mandatory requirement for 
 all vehicles manufactured since 1997 in many countries. It specifies a number 
 of protocols that manufacturers must implement for diagnostic scan tools to 
 communicate with engine control units (ECU). These protocols are used for 
 monitoring and troubleshooting vehicle drive trains, chassis and electrical 
 systems. Implementing a hardware interface is relatively easy with a basic 
 knowledge of electronics and one of the OBD interpreter kits available from 
 popular electronics stores (See section 5).


## 2. Design


## 3. User Interface


## 4. OBD-II Protocol

### 4.1 OSI and SAE Standards

 1 - SAE J1850 PWM (Ford)
 2 - SAE J1850 VPW (GM, Isuzu)
 3 - IS0 9141-2
 4 - ISO 14230-4 KWP2000 (5-baud init.)
 5 - IS0 14230-4 KWP2000 (Fast init.)
 6 - IS0 15765-4 CAN
 7 - IS0 15765-4 CAN
 8 - IS0 15765-4 CAN
 9 - IS0 15765-4 CAN 
 A - SAE J1939 CAN
 B - USER1 CAN
 C - USER2 CAN
 
### 4.2 Diagnostic Test Modes

The SAE J1979 standard currently defines ten possible diagnostic test modes:
 01 - show current data
 02 - show freeze frame data
 03 - show diagnostic trouble codes
 04 - clear trouble codes and stored values
 05 - test results, oxygen sensors
 06 - test results, non-continuously monitored
 07 - show pending trouble codes
 08 - special control mode
 09 - request vehicle information
 0A - request permanent trouble codes










### 4.2 Diagnostic Trouble Codes (DTC)


### 4.3 Parameter Identifiers (PID)


 
## 5. Hardware Interfaces
 
### 5.1 Integrated Circuits and Projects
 
  1. ELM327 OBD Interpreter - https://www.elmelectronics.com/wp-content/uploads/2016/07/ELM327DS.pdf
  2. STN1110 OBD Interpreter - http://www.obdsol.com/solutions/chips/stn1110/
  3. Sparkfun Car Diagnostics Kit - https://www.sparkfun.com/products/10769
  4. Altronics OBD Interpreter Kit - http://www.altronics.com.au/p/k4065-obdii-automotive-interpreter-kit/

### 5.2 Pics


## 6. Notes
