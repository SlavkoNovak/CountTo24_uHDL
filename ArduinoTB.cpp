/*
	ArduinoTB.cpp
	ArduinoTB v0.1 by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#include "config.h"

#ifdef ARDUINO_TB 
#include <windows.h>
#include "ArduinoTB.h"

unsigned int PINS[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned long int __millis__ = 0;
bool DoSimulation = true;

int main(int argc, char **argv)
{
	setup();
	
	while(DoSimulation)
	{
		loop();
		Sleep(LOOP_SLEEP);
		__millis__ += LOOP_SLEEP;
	}
}

uint8_t digitalRead(uint8_t pin)
{
	cout << "digitalRead; pin: " << (int)pin << ", val: " << PINS[pin] << endl;
	return PINS[pin];
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	cout << "digitalWrite; pin: " << (int)pin << ", val: " << (int)val << endl;
	PINS[pin] = val;
}

void pinMode(uint8_t pin, uint8_t mode)
{
	cout << "pinMode; pin: " << (int)pin << ", mode: " << (int)mode << endl;
}

unsigned long millis()
{
	return __millis__;
}

unsigned long micros()
{
	return __millis__ * 1000;
}

void ExitStimulation()
{
	DoSimulation = false;
	cout << "SIMULATION DONE!" << endl;
}

#endif
