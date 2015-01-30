/*
	Multiplexer.h
	CountTo24_uHDL v0.5by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#ifndef _MULTIPLEXER_H
#define _MULTIPLEXER_H

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

uMODULE(Multiplexer)
{
	//Inputs
	u_input<bool> InternalClk;
	u_input<bool> ExternalClk;
	u_input<bool> ExternalSel;
	
	//Outputs
	u_output<bool> Output;
	
	//Init method
	uINIT(Multiplexer)
	{
		InternalClk.Write(false);
		ExternalClk.Write(false);
		ExternalSel.Write(false);
		
		modules.Add(this);
	}
	
	//Sensetivity and always method
	uALWAYS(
			InternalClk.Change() || ExternalClk.Change() || ExternalSel.Change(),
			if(true == ExternalSel.Read())
			{
				Output.Write(ExternalClk.Read());
			}
			else
			{
				Output.Write(InternalClk.Read());
			}
			)
};

#endif
