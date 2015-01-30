/*
	Count24MainTB.h
	CountTo24_uHDL v0.5by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#ifndef _COUNT_24_MAIN_TB_H
#define _COUNT_24_MAIN_TB_H

#include "config.h"

#ifdef ARDUINO_TB
#include <ArduinoTB.h>
	
using namespace uHDL;
using namespace std;

//Stimulus module
uMODULE(Count24MainTB)
{
	uINIT(Count24MainTB)
	{
		PINS[12] = true;
		
		modules.Add(this);
	}
	
	void stimulus()
	{
		uDO_ON_ms(15000) PINS[12] = false;

		uDO_ON_ms(11000) PINS[14] = true;
		uDO_ON_ms(12000) PINS[14] = false;

		uDO_ON_us(21000000) PINS[12] = true;
		uDO_ON_us(20000000) PINS[12] = false;

		uDO_ON_tick(600) PINS[12] = true;
		uDO_ON_tick(601) PINS[12] = false;

		#ifdef ARDUINO_TB
			cout << "TB; uHDL::TICKS: " << uHDL::TICKS << ", modCount24Main.ClckOut: " << (bool)modCount24Main.ClckOut.Read() << endl;
			cout << "TB; uHDL::TICKS: " << uHDL::TICKS << ", modCount24Main.HourOut: " << (int)modCount24Main.HourOut.Read() << endl;
			cout << "TB; modCount24Main.multiplexer.InternalClk: " << (bool)modCount24Main.multiplexer.InternalClk.Read() << endl;
			cout << "TB; modCount24Main.multiplexer.ExternalClk: " << (bool)modCount24Main.multiplexer.ExternalClk.Read() << endl;
		#endif
		
		uDO_ON_ms(70200) ExitStimulation();
	}
	
	uALWAYS(true, stimulus();)
};


#endif
#endif
