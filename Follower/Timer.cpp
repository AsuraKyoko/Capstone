#include "Timer.h"

Timer::Timer(int trig)
{
	this->trig = trig;
}

bool Timer::update()
{
	return count++ >= trig;
}

int Timer::getCount()
{
	return count;
}
