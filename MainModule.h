/*
	MainModule.h
	CountTo24_uHDL v0.5by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#ifndef _MAIN_MODULE_H
#define _MAIN_MODULE_H

//#include "uHDL.h"
#include "config.h"

#ifdef ARDUINO_TB
	#include "ArduinoTB.h"
	#include <iostream>
#else
	#include "Arduino.h"
#endif
	
using namespace uHDL;
using namespace std;

//Main module -->
uMODULE(Count24Main)
{
	//Inputs
	u_input<bool> ClckInHour;
	u_input<bool> ClckInT;
	
	//Outputs
	u_output<u_byte> HourOut;
	u_output<bool> ClckOut;
	
	//Submodules
	ClockMillis clock;
	Counter24 countHour;
	TFlipFlopPosEdg clckIn;
	
	//Signals
	u_signal<bool> countHour_clckIn;
	
	//Init method
	uINIT(Count24Main)
	{
		clckIn.Clck.Write(false);
		clock.Delay_ms.Write(1000);
		clock.ClckOut.Connect(&countHour_clckIn);
		//countHour.ClckIn.Connect(&countHour_clckIn);
		
		modules.Add(this);
		modules.Add(&clckIn); //Primitive module must be added
		modules.Add(&clock); //Primitive module must be added
	}
	
	//Module method
	void Count24MainMethod()
	{
		clckIn.Clck.Write(ClckInT.Read());
		if(clckIn.Output.Read())
		{
			countHour.ClckIn.Write(clock.ClckOut.Read());
		}
		else
		{
			if(ClckInHour.Change()) countHour.ClckIn.Write(ClckInHour.Read());
		}
		
		HourOut.Write(countHour.Output.Read());
		ClckOut.Write(countHour.ClckOut.Read());
	}
	
	//Sensitivity and always method
	uALWAYS(true, Count24MainMethod();)
};
//<-- Main module

//Main module instance
extern Count24Main modCount24Main;

#endif
