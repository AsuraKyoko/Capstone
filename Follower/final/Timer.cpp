#include "Timer.h"

Timer::Timer(int trig)
{
    this->count = 0;
	this->trig = trig;
}

bool Timer::update()
{
//    printf("Timer location: %d", this);
//    printf("Timer count: %d", count);
//    printf("Timer trigg: %d", trig);
    
	if(count++ >= trig)
    {
        return true;
    }
    
    return false;
}

Timer* Timer::reset(Timer *timer, int count)
{
    if(timer != NULL)
    {
        delete timer;
    }
    
    return new Timer(count);
}