//
// ___FILENAME___ 
// Main file
// ----------------------------------
// Developed with embedXcode 
// http://embedXcode.weebly.com
//
// Project ___PROJECTNAME___
//
// Created by ___FULLUSERNAME___, ___DATE___ ___TIME___
// ___ORGANIZATIONNAME___
//	
//
// Copyright © ___FULLUSERNAME___, ___YEAR___
// Licence CC = BY NC SA
//
// See ___PACKAGENAME___.pde and ReadMe.txt for references
//
// ----------------------------------
// DO NOT EDIT THIS FILE.
// THE SKETCH IS IN ___PACKAGENAME___.pde
// ----------------------------------
//


// Core library - MCU-based
#if defined (__AVR_ATmega328P__) || defined (__AVR_ATmega2560__) || defined(__AVR_ATmega32U4__) // Arduino specific
  #if defined(ARDUINO) && (ARDUINO >= 100)
  #include "Arduino.h" // for Arduino 1.0
  #else
  #include "WProgram.h" // for Arduino 23
  #endif
#elif defined(__32MX320F128H__) || defined(__32MX795F512L__) // chipKIT specific 
#include "WProgram.h"
#elif defined(__AVR_ATmega644P__) // Wiring specific
#include "Wiring.h"
#elif defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) || defined(__MSP430FR5739__) // LaunchPad specific
#include "Energia.h"
#elif defined(MCU_STM32F103RB) || defined(MCU_STM32F103ZE) || defined(MCU_STM32F103CB) || defined(MCU_STM32F103RE) // Maple specific
#include "WProgram.h"	
#else // error
#error Platform not defined
#endif

// Sketch
#include "___PACKAGENAME___.pde"

int main(void)
{
#if defined(__AVR_ATmega644P__) // Wiring specific
  boardInit();
#else
  init();
  
#if defined(USBCON) // Arduino 1.0 specific
  USBDevice.attach();
#endif
  
#endif
  
  setup();
  for (;;) {
    
    loop();
    
#if defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 specific
    if (serialEventRun) serialEventRun();
#endif
  }
  
  return 0;
}
