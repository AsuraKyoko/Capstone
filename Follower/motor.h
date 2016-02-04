//
//  motor.h
//  motors
//
//  Created by Peter Tuerk on 10/20/14.
//  Copyright (c) 2014 SKPI. All rights reserved.
//

#ifndef motors_motor_h
#define motors_motor_h

#ifdef __linux

#include "bcm2835.h"

class Motor
{
private:
    uint8_t f;
    uint8_t b;
    
    Motor(){};
    
public:
    Motor(uint8_t f,uint8_t b);
    
    void on(bool forward);
    void brake(); 
    void off();
    
    void update(unsigned char direction, unsigned int delay);
};

#endif

#endif
