#pragma once
#include "Header.h"

class Timer {
public:
	/*
	Creates the timer class objects with default parameters.
	*/
	Timer();

	/*
	Read actual SDL_GetTicks() value and set object's parameters with it.
	*/
	void timerStart();

	/*
	Returns time form timerStart().
	If timer was not started returns 0;
	*/
	Uint32 getTime();

private:
	Uint32 startTime;
	bool isStarted;
};