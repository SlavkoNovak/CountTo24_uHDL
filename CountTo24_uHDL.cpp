/*
	ABinClock.cpp
	ABinClock v0.5 by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#include "config.h"

//Modules instance
uMODULES(modules, NUM_OF_MODULES)
uHDL::u_signal<bool> countHour_clckIn;

//Main module instance
Count24Main modCount24Main;

#ifdef ARDUINO_TB
//TB instance
Count24MainTB tb;
#endif

void setup()
{	
	//Set input pins
	pinMode(14, INPUT);
	pinMode(12, INPUT_PULLUP);
	
	//Set output pins
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);

	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(13, OUTPUT);
		
	//Connect signals to module
	modCount24Main.ClckInHour.Connect(&countHour_clckIn);
 countHour_clckIn.Write(1);
 modCount24Main.ClckInT.Write(1);
}

void loop()
{
	//Read inputs
	countHour_clckIn.Write(digitalRead(14));
	modCount24Main.ClckInT.Write(digitalRead(12));


	//Do uHDL engine clocking
	//uHDL::uMain(1, Modules);
	uHDL::uMain(modules);
	
	//Write outputs
	digitalWrite(2, uGetBit(modCount24Main.HourOut.Read(), 0));
	digitalWrite(3, uGetBit(modCount24Main.HourOut.Read(), 1));

	digitalWrite(4, uGetBit(modCount24Main.HourOut.Read(), 2));
	digitalWrite(5, uGetBit(modCount24Main.HourOut.Read(), 3));
	digitalWrite(6, uGetBit(modCount24Main.HourOut.Read(), 4));
	digitalWrite(13, modCount24Main.ClckOut.Read());
}
