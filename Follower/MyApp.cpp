//
//  MyApp.cpp
//  Follower
//
//  Created by Steve Mahar on 4/7/15
//  Copyright (c) 2015 GROMOS. All rights reserved.
//

#include "MyApp.h"

void MyApp::init()
{
	printf("initing\n");
	if (!bcm2835_init())
	{
		printf("init failed\n");
		setQuit(true);
        return;
	}
   	
    // Set RPI pin P1-22 to be an input
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_INPT);
    //  with a pullup
	bcm2835_gpio_set_pud(PIN1, BCM2835_GPIO_PUD_UP);

	// Set RPI pin P1-22 to be an input
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_INPT);
    //  with a pullup
    bcm2835_gpio_set_pud(PIN2, BCM2835_GPIO_PUD_UP);

	//setup motors
	leftMotor = new Motor(RPI_GPIO_P1_16, RPI_GPIO_P1_15);
	rightMotor = new Motor(RPI_GPIO_P1_12, RPI_GPIO_P1_11);

	state = STATE_NORMAL_FOLLOW;
	scanDirection = true; // will scan to the left
    
    tick = 0;
    
	printf("init complete\n");
}

void MyApp::run()
{
    int i = 0;
    printf("HERE %i\n", i++);
	bool lineDetected = false;
    printf("HERE %i\n", i++);
    while(!shouldQuit())
    {
        printf("HERE %i\n", i++);
		uint8_t lvalue = bcm2835_gpio_lev(PIN1);
        printf("HERE %i\n", i++);
		uint8_t rvalue = bcm2835_gpio_lev(PIN2);
        printf("HERE %i\n", i++);
        printf("read from pins: %d % d\n", lvalue, rvalue);
		switch(state)
        {
		case 0:	// Normal follow state
        {
			if(lvalue == 1 && rvalue == 1)
			{
				state = STATE_FOUND_NODE;
				lineDetected = false;
				break;
			}

			if(lvalue == 0)
				leftMotor->on(true);
			else
				leftMotor->on(false);
			if(rvalue == 0)
					rightMotor->on(true);
			else
					rightMotor->on(false);
			break;
        }
		case 1:	// Found node state
			if(lvalue == 0 && rvalue == 0)
			{
                stop();
				state = 69;
			}
			else
			{
				if(lvalue == 1)
					leftMotor->on(true);
				else
					leftMotor->brake();
				if(rvalue == 1)
					rightMotor->on(true);
				else
					rightMotor->brake();
			}
			break;
		case 2:
			if(lineDetected)
			{
				if(lvalue == 0 && rvalue == 1)
					state = STATE_NORMAL_FOLLOW;
				else
				{
                    turnLeft();
				}
			}
			else
			{
				if(lvalue == 1)
					lineDetected = true;
                turnLeft();
			}
			break;
        case 3:	// scan for line state
            if(tick++ >= TICK_TRIG)
            {
                tick = 0;
                state = STATE_SCAN_LEFT;
            }
            break;
		default:
        {
			stop();
			printf("found node\n");
			break;
		}
        }
    }

    stop();
    leftMotor->off();
    rightMotor->off();
}

void MyApp::destroy()
{
    leftMotor->off();
    rightMotor->off();
    
    delete leftMotor;
    delete rightMotor;
    bcm2835_close();
}

void MyApp::message(GMessage *msg)
{
    printf("App Recieved [%i]\n", (short)msg->getBuffer()[0]);
}

void MyApp::turnLeft()
{
    leftMotor->on(false);
    rightMotor->on(true);
}

void MyApp::goForward()
{
    leftMotor->on(true);
    rightMotor->on(true);
}

void MyApp::stop()
{
    leftMotor->brake();
    rightMotor->brake();
}




            
            
            
            
