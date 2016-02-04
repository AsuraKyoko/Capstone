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
    if (!bcm2835_init())
	{
		setQuit(true);
        return;
	}
    // Set RPI pin P1-22 to be an input
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
    //  with a pullup
    bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP);
}

void MyApp::run()
{
    while(!shouldQuit())
    {
        // Read some data
        uint8_t value = bcm2835_gpio_lev(PIN);
        printf("read from pin 22: %d\n", value);
        
        // wait a bit
        //
        delay(500);
    }
}

void MyApp::destroy()
{
    bcm2835_close();
}

void MyApp::message(GMessage *msg)
{
    printf("App Recieved [%i]\n", (short)msg->getBuffer()[0]);
}



            
            
            
            
            
