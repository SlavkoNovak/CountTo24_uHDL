/*
	Counter24.h
	CountTo24_uHDL v0.5 by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#ifndef _COUNTER_24_H
#define _COUNTER_24_H

#include "config.h"

#ifdef ARDUINO_TB
	#include "ArduinoTB.h"
	#include <iostream>
#else
	#include "Arduino.h"
#endif

using namespace uHDL;
using namespace std;

uMODULE(Counter24)
{
	//Inputs
	u_input<u_byte> Input;
	u_input<bool> Set;
	u_input<bool> ClckIn;
	
	//Outputs
	u_output<u_byte> Output;
	u_output<bool> ClckOut;	
	
	//Init Method
	uINIT(Counter24)
	{
		Input.Write(0);
		Set.Write(false);
		Output.Write(0);
		ClckOut.Write(false);
		
		modules.Add(this);
	}
	
	//Module Method
	void CountMethod()
	{
		if(Set.Change())
		{
			Output.Write(Input.Read());
		}
		
		if(ClckIn.Change())
		{
			Output.Write(Output.Read() + 1);
			if(24 == Output.Read())
			{
				Output.Write(0);
				ClckOut.Write(true);
			}
			else ClckOut.Write(false);
		}
	}
	
	//Sensitivity and always method
	uALWAYS(ClckIn.NegEdge() || Set.PosEdge(), CountMethod(););
};

#endif
