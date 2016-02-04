//
//  MyApp.cpp
//  Follower
//
//  Created by Steve Mahar on 4/7/15
//  Copyright (c) 2015 GROMOS. All rights reserved.
//

#include "MyApp.h"

// TODO: replace global functions
void followLine(uint8_t lvalue, uint8_t rvalue, Motor *leftMotor, Motor *rightMotor, bool color);

// Platform Requirement
// Run once when the app starts
void MyApp::init()
{

    //Init the gpio library or FAIL
	if (!bcm2835_init())
	{
		printf("FAILED: bcm2835init()\n");
		setQuit(true);
        return;
	}

   	//Init the two input pins
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_set_pud(PIN1, BCM2835_GPIO_PUD_UP);

    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(PIN2, BCM2835_GPIO_PUD_UP);

	//setup motors
	motor = new Motor(RPI_GPIO_P1_16, RPI_GPIO_P1_15);
	rightMotor = new Motor(RPI_GPIO_P1_12, RPI_GPIO_P1_11);
    leftMotor = new Motor(RPI_GPIO_P1_16, RPI_GPIO_P1_15);

    // setup state machine
	state = STATE_NORMAL_FOLLOW;
	scanDirection = SCAN_LEFT;
    timer = NULL;
}

// Platform Requirement
// Run once after the init function
void MyApp::run()
{
    while(!shouldQuit())
    {
        // get input pin values
		uint8_t lvalue = bcm2835_gpio_lev(PIN1);
		uint8_t rvalue = bcm2835_gpio_lev(PIN2);
        //printf("read from pins: %d % d\n", lvalue, rvalue);
        
        if(lastState != state)
        {
            printf("State Change: %d\n", state);
        }
        
        lastState = state;
        
		switch(state)
        {
        case STATE_NORMAL_FOLLOW:
            if(lvalue == FOLLOW_BLACK && rvalue == FOLLOW_BLACK)
            {
                state = STATE_FOUND_NODE;
                break;
            }

            followLine(lvalue, rvalue, leftMotor, rightMotor, FOLLOW_WHITE);
			break;

        case STATE_FOUND_NODE:
            if(lvalue == FOLLOW_WHITE && rvalue == FOLLOW_WHITE)
            {
                leftMotor->on(true);
                rightMotor->on(true);
                
                timer = Timer::reset(timer, 800);
                    
                state = STATE_TICK;
                nextState = STATE_SCAN_LEFT;
                break;
            }
            
            followLine(lvalue, rvalue, leftMotor, rightMotor, FOLLOW_BLACK);
            break;
                
		case STATE_SCAN_LEFT:
            if(lvalue == 1)
            {
				timer = Timer::reset(timer, 100);
                state = STATE_TICK;
				nextState = STATE_NORMAL_FOLLOW;
                break;
            }
                
            leftMotor->on(false);
            rightMotor->on(true);
			break;
                
        case STATE_TICK:
            printf("TICK %d\n", timer);
            if(timer->update())
            {
                state = nextState;
            }
            break;
                
		default:
            printf("default case\n");
            
            leftMotor->brake();
            rightMotor->brake();
            
            leftMotor->off();
            rightMotor->off();
            
            setQuit(true);
			break;
        }
    }

    leftMotor->brake();
    rightMotor->brake();
    
    leftMotor->off();
    rightMotor->off();
}

// Platform Requirement
// Run once after the destroy function
void MyApp::destroy()
{
    // clean up timer
    if(timer != NULL)
    {
        delete timer;
    }
    
    // clean up motors
    leftMotor->off();
    rightMotor->off();
    
    delete leftMotor;
    delete rightMotor;
    
    // clean up gpio library
    bcm2835_close();
}

// Platform Requirement
// Run when the platform has a message
void MyApp::message(GMessage *msg)
{
    //print incoming message type
    printf("App Recieved Message Type: [%i]\n", (short)msg->getBuffer()[0]);
}

void followLine(uint8_t lvalue, uint8_t rvalue, Motor *leftMotor, Motor *rightMotor, bool color)
{
    if(lvalue == color)
    {
        leftMotor->on(true);
    }
    else
    {
        leftMotor->on(false);
    }
    if(rvalue == color)
    {
        rightMotor->on(true);
    }
    else
    {
        rightMotor->on(false);
    }
}




            
            
            
            
