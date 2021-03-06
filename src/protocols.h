/* 
   Project: OBD-II Monitor (On-Board Diagnostics)

   Author: Derek Chadwick

   Description: OBD and AT message crackers. 
                If the message starts with ASCII hex digits '40'...'49' then
                the message is from the ECU. Otherwise it is a message from
                the OBD interface IC or is invalid.


   Selected ECU Mode 01 Parameters: 
   
   [PID] [Data Bytes] [Min Value] [Max Value] [Formula]           [Description]
    05    1            -40         215         A - 40             (ECT Centigrade)
    0A    1            0           765         3 * A              (Fuel Pressure kPa)
    0B    1            0           255         A                  (MAP Pressure kPa)
    0C    2            0           16,383.75   (256 * A + B) / 4  (Engine RPM)
    0D    1            0           255         A                  (Vehicle Speed)
    0E    1            -64         63.5        (A / 2) - 64       (Timing Advance: degrees before TDC) 
    0F    1            -40         215         A - 40             (IAT Centigrade)
    11    1            0           100         100 / 255 * A      (Throttle Position %)
    2F    1            0           100         100 / 255 * A      (Fuel Tank Level %)
    5A    1            0           100         100 / 255 * A      (Relative Accelerator Pedal Position %)
    5C    1            -40         215         A - 40             (Oil Temperature)
    5E    2            0           3276.75     (256 * A + B) / 20 (Fuel Flow Rate L/h)



   Selected ECU Mode 09 Parameters:
 
   [PID] [Data Bytes] [Description] 
    02    17           VIN - Vehicle Identification Number
    0A    20           ECU Name
         
     
   Selected ECU Mode 21 Parameters (Toyota):
   
       
                     
   Selected ECU Mode 22 Parameters (GM/Isuzu):
        
    (Oil Pressure? Mode: 22 PID: 115C)
    
    
    
   Date: 7/11/2017
   
*/

#ifndef OBD_PROTOCOLS_INCLUDED
#define OBD_PROTOCOLS_INCLUDED

#include "uthash.h"

/* Constant Definitions. */

#define ECU_ECT_TEMPERATURE_MAX 215.0
#define ECU_ECT_TEMPERATURE_IN -40.0 
#define ECU_VEHICLE_SPEED_MAX 200.0
#define ECU_VEHICLE_SPEED_MIN 0.0
#define ECU_IAT_TEMPERATURE_MAX 215.0
#define ECU_IAT_TEMPERATURE_MIN -40.0
#define ECU_ENGINE_RPM_MAX 8000.0
#define ECU_ENGINE_RPM_MIN 0.0
#define ECU_MAP_PRESSURE_MAX 255.0
#define ECU_MAP_PRESSURE_MIN 0.0

/* OBD Message Types. */
#define OBD_MSG_MODE01_PARAMETER 1
#define OBD_MSG_VOLTAGE 2
#define OBD_MSG_INTERFACE 3
#define OBD_MSG_PROTOCOL 4
#define OBD_MSG_MODE03_PARAMETER 5
#define OBD_MSG_MODE09_PARAMETER 6

/* Type Definitions. */

struct _ECU_Parameters {
   double ecu_engine_rpm;
   double ecu_vehicle_speed;
   double ecu_coolant_temperature;
   double ecu_intake_air_temperature;
   double ecu_manifold_air_pressure;
   double ecu_oil_pressure;
   double ecu_egr_pressure;
   double ecu_battery_voltage;
   double ecu_throttle_position;
   double ecu_oil_temperature;
   double ecu_accelerator_position;
   double ecu_fuel_pressure;
   double ecu_fuel_flow_rate;
   double ecu_fuel_tank_level;
   double ecu_timing_advance;
   int ecu_mil_status;
   int ecu_dtc_count;
   char ecu_last_dtc_code[16];
   char ecu_vin[256];
   char ecu_name[256];
   char ecu_manufacturer[256];
   char battery_voltage[256];
};

typedef struct _ECU_Parameters ECU_Parameters;

struct _OBD_Interface {
   unsigned int obd_interface_status;
   unsigned int obd_rs232_baud;
   unsigned int obd_stop_bits;
   unsigned int obd_data_bits;
   unsigned int obd_parity_bits;
   int obd_protocol_number;
   char obd_protocol_name[256];
   char obd_interface_name[256];
};

typedef struct _OBD_Interface OBD_Interface;

struct _PID_Parameters {
   char pid_code[16];
   unsigned int pid_num;
   unsigned int pid_supported;
   unsigned int pid_data_bytes;
   unsigned int pid_scale_factor;
   char pid_formula[256];
   char pid_description[256];
   char pid_gauge_label[32];
   UT_hash_handle hh;
};

typedef struct _PID_Parameters PID_Parameters;

struct _DTC_Parameters {
   char dtc_code[16];
   unsigned int dtc_number;
   unsigned int dtc_set;
   char dtc_description[256];
   char dtc_date_time[256];
   UT_hash_handle hh;
};

typedef struct _DTC_Parameters DTC_Parameters;

/* Function Declarations. */

/* OBD Interface Status. */
void set_interface_on();
void set_interface_off();
int get_interface_status();
void set_obd_protocol_number(int obdpnum);
int get_obd_protocol_number();
void set_obd_protocol_name(char *obdname);
void get_obd_protocol_name(char *info);
void set_interface_information(char *ii_msg);
void get_interface_information(char *info);
void get_vehicle_vin(char *vin);
void get_ecu_name(char *ecu);

/* ECU Parameter Get/Set Functions. */

void set_ecu_parameters(ECU_Parameters *ecup);
void get_ecu_parameters(ECU_Parameters *ecup);

double get_engine_rpm();
double get_coolant_temperature();
double get_manifold_pressure();
double get_intake_air_temperature();
double get_battery_voltage();
double get_vehicle_speed();
double get_egr_pressure();
double get_oil_temperature();
double get_oil_pressure();
double get_throttle_position();
double get_fuel_tank_level();
double get_fuel_flow_rate();
double get_fuel_pressure();
double get_accelerator_position();
double get_timing_advance();

int get_mil_status();
int get_dtc_count();
void get_last_dtc_code(char *code_buf);

/* Message Parsers. */
int parse_obd_msg(char *obd_msg);


#endif

