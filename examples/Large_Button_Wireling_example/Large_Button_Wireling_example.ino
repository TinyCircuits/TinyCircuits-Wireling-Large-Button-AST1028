/*************************************************************************
 * Large Button Wireling Example
 * Uses digitalRead to detect when the large button is pressed and report  
 * state to the Serial Monitor
 * 
 * Hardware by: TinyCircuits
 * Written by: Zachary Lee for TinyCircuits
 * 
 * Initiated: 07/25/2019
 * Last Updated: 12/04/2019 
 *************************************************************************/

#include <Wire.h>
#include <Wireling.h> // For interfacing with Wirelings

#define buttonPin A0 // corresponds to Port 0. Similarly, Port 1 = A1, Port 2 = A2, Port 3 = A3.

// Make Serial Monitor compatible for all TinyCircuits processors
#if defined(ARDUINO_ARCH_AVR)
  #define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
  #define SerialMonitorInterface SerialUSB
#endif

void setup() {
  Wire.begin();                         // Begin I2C Communication
  SerialMonitorInterface.begin(9600);   // Begin Serial Communication and set Baud Rate

  // Enable & Power Wireling
  Wireling.begin();

  pinMode(buttonPin, INPUT); // The button is an input 
}

void loop() {
  static int buttonState = 0;
  int prevButtonState = buttonState;
  buttonState = digitalRead(buttonPin);   // Poll Sensor Data

  if (prevButtonState != buttonState) // no need to alert the user if button state remains unchanged
  {
    if (buttonState == LOW)
    {
      SerialMonitorInterface.println("Button pressed!");
    }
    else
    {
      // button not currently being pressed
    }
  }
  Wireling.disablePower();
}
