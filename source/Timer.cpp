#include "Timer.h"

Timer::Timer() {
	startTime = 0;
	isStarted = false;
}

void Timer::timerStart() {
	startTime = SDL_GetTicks();
	isStarted = true;
}

Uint32 Timer::getTime() {
	if (isStarted) {
		return (SDL_GetTicks() - startTime);
	}
	return 0;
}