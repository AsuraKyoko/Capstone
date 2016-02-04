#ifndef TIMER_H
#define TIMER_H

#include "stdio.h"

// Timer class to measure "cpu cycles"
class Timer
{
private:
    //Timer variables
	int count;
	int trig;

public:
	Timer(int trig);
    
	bool update();
    static Timer *reset(Timer *timer, int count);
    
	int getCount(){return count;}
    int getTrig(){return trig;}
};

#endif//TIMER_H