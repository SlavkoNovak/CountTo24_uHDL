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
	
	//Signals
	u_signal<bool> multiplexer_Internal;
	u_signal<bool> multiplexer_External;
	u_signal<bool> multiplexer_ExternalSel;
	u_signal<bool> countHour_clckIn;
	
	//Submodules
	ClockMillis clock;
	Counter24 countHour;
	TFlipFlopPosEdg clckIn;
	Multiplexer multiplexer;

	//Init method
	uINIT(Count24Main)
	{
		clckIn.Clck.Write(false);
		clock.Delay_ms.Write(1000);
		
		#ifdef U_HDL_WIREING
		//Wire input
		ClckInT.WireTo(&clckIn.Clck);
		ClckInHour.WireTo(&multiplexer.ExternalClk);
		
		//Wire output
		countHour.Output.WireTo(&HourOut);
		countHour.ClckOut.WireTo(&ClckOut);
		#endif
		
		clock.ClckOut.Connect(&multiplexer_Internal);
		multiplexer.InternalClk.Connect(&multiplexer_Internal);
		
		multiplexer.ExternalClk.Connect(&multiplexer_External);
		
		clckIn.Output.Connect(&multiplexer_ExternalSel);
		multiplexer.ExternalSel.Connect(&multiplexer_ExternalSel);
		
		multiplexer.Output.Connect(&countHour_clckIn);
		countHour.ClckIn.Connect(&countHour_clckIn);
		
		modules.Add(this);
		modules.Add(&clckIn); //Primitive module must be added
		modules.Add(&clock); //Primitive module must be added
	}
	
	#ifndef U_HDL_WIREING
	//Module method
	void Count24MainMethod()
	{
		//Wire input
		multiplexer_External.Write(ClckInHour.Read());
		clckIn.Clck.Write(ClckInT.Read());
		
		//Wire output
		HourOut.Write(countHour.Output.Read());
		ClckOut.Write(countHour.ClckOut.Read());
	}
	
	//Sensitivity and always method
	uALWAYS(true, Count24MainMethod();)
	#endif
};
//<-- Main module

//Main module instance
extern Count24Main modCount24Main;

#endif
