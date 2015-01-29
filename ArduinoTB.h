/*
	ArduinoTB.h
	ArduinoTB v0.1 by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#ifndef _ARDUINOTB_H
#define _ARDUINOTB_H

#include <iostream>

#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

extern unsigned int PINS[22];

void setup();
void loop();

void pinMode(uint8_t, uint8_t);
uint8_t digitalRead(uint8_t);
void digitalWrite(uint8_t, uint8_t);
unsigned long millis();
unsigned long micros();
void ExitStimulation();

#endif
