//
//  MyApp.h
//  Follower
//
//  Created by Peter Tuerk on 1/7/15.
//  Copyright (c) 2015 GROMOS. All rights reserved.
//

#ifndef MY_APP_H
#define MY_APP_H

#include <bcm2835.h>

#include <stdio.h>
#include "../grom/GromOSAPI/GromOSAPI/GromApp.h"

#include "motor.h"

// Defines the pin number
#define PIN2 RPI_GPIO_P1_18
#define PIN1 RPI_GPIO_P1_22

// State Machine states
#define STATE_NORMAL_FOLLOW 0
#define STATE_FOUND_NODE 1
#define STATE_SCAN_LEFT 2
#define STATE_TICK 3

#define TICK_TRIG 5


class MyApp : public GromApp
{
public:
    int tick;
	int state;
	bool scanDirection;
    
    Motor *leftMotor;
    Motor *rightMotor;

    void init();
    void run();
    void destroy();
    void message(GMessage *msg);
    
    void turnLeft();
    void goForward();
    void stop();
};

#endif//MY_APP_H
