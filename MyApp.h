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

// Defines the pin number
#define PIN RPI_GPIO_P1_22

class MyApp : public GromApp
{
public:
    
    void init();
    void run();
    void destroy();
    void message(GMessage *msg);
};

#endif//MY_APP_H
