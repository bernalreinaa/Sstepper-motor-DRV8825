
//==============================================================================
//==============================================================================
//Example sketch to control a stepper motor with DRV8825 stepper motor driver, 
//  AccelStepper library and Arduino: acceleration and deceleration.
//==============================================================================
//==============================================================================


//------------------------------------------------------------------------------
//-----------------------MICROCONTROLLER AND DRIVER-----------------------------
// MCU:			ATMEGA328P (ARDUINO Nano)
// DRIVER:  DRV8825
//-------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//-------------------------------LIBRARY----------------------------------------

#include <AccelStepper.h>
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//---------------------------PIN DEFINITION-------------------------------------
// Define stepper motor connections and motor interface type. 
// Motor interface type must be set to 1 when using a driver:
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//--------------------------------INSTANCES-------------------------------------
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//---------------------------MAIN (SETUP)---------------------------------------
void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(200);
  stepper.setAcceleration(30);
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//-----------------------------------LOOP---------------------------------------
void loop() {

  stepper.moveTo(800);        // Set the target position:
  stepper.runToPosition();    // Run to target position with set speed and 
                              //  acceleration/deceleration:

  delay(1000);                // Delay (1s)


  stepper.moveTo(0);          // Set the target position:
  stepper.runToPosition();    // Run to target position with set speed and 
                              //  acceleration/deceleration:

  delay(1000);              // Delay (1s)
  
}
//------------------------------------------------------------------------------





