/*
	config.h
	CountTo24_uHDL v0.5 by Slavko Novak [slavko.novak.esen@gmail.com], January 2015
	License: LGPL
*/

#ifndef _CONFIG_H
#define _CONFIG_H

//Set ARDUINO_TB define for simulation
#define ARDUINO_TB

//Set U_HDL_WIREING define for wireing API
#define U_HDL_WIREING

#include "uHDL.h"
#include "uHDL_Primitives.h"

//Declare module list
#define NUM_OF_MODULES 6
extern uMODULES(modules, NUM_OF_MODULES)

#include "Counter24.h"
#include "Multiplexer.h"
#include "MainModule.h"

#ifdef ARDUINO_TB
	#include <cstdio>
	#include <string>
	#include <iostream>
	#include "Count24MainTB.h"
	#define LOOP_SLEEP 50
	using namespace std;
#else
	#include <Arduino.h>
#endif

#endif
