//
//  MyApp.h
//  Follower
//
//  Created by Peter Tuerk on 1/7/15.
//  Copyright (c) 2015 GROMOS. All rights reserved.
//

#ifndef MY_APP_H
#define MY_APP_H

#include <stdio.h>
#include <bcm2835.h>

// Platform requirements
#include "../grom/GromOSAPI/GromOSAPI/GromApp.h"

// Custom classes
#include "Timer.h"
#include "motor.h"

// Define the input pins
#define PIN2 RPI_GPIO_P1_18
#define PIN1 RPI_GPIO_P1_22

// State Machine states
#define STATE_NORMAL_FOLLOW 0
#define STATE_FOUND_NODE    1
#define STATE_SCAN_LEFT     2
#define STATE_TICK          3

// Scan Directions
#define SCAN_LEFT   true
#define SCAN_RIGHT  false

// Follow Color
#define FOLLOW_WHITE 0
#define FOLLOW_BLACK 1

// Platform requirements
class MyApp : public GromApp
{
public:
    // Motor variable
    Motor *leftMotor;
    Motor *rightMotor;
    Motor *motor;
    
    // Scan Direction
    bool scanDirection;
    
    // State Machine variables
	int state;
    int nextState;
    int lastState;
    
    // The states timer
    Timer *timer;

    // Platform Requirements
    void init();
    void run();
    void destroy();
    void message(GMessage *msg);
};

#endif//MY_APP_H
