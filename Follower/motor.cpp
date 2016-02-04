//
//  motor.cpp
//  motors
//
//  Created by Peter Tuerk on 10/20/14.
//  Copyright (c) 2014 SKPI. All rights reserved.
//

#include "motor.h"

#ifdef __linux

Motor::Motor(uint8_t f,uint8_t b)
{
    this->f = f;
    this->b = b;
    
    bcm2835_gpio_fsel(f, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(b, BCM2835_GPIO_FSEL_OUTP);
}

void Motor::on(bool forward)
{
    off();
    
    if(forward)
    {
        bcm2835_gpio_write(f, HIGH);
    }
    else
    {
        bcm2835_gpio_write(b, HIGH);
    }
}

void Motor::brake()
{
    bcm2835_gpio_write(f, HIGH);
    bcm2835_gpio_write(b, HIGH);
}

void Motor::off()
{
    bcm2835_gpio_write(f, LOW);
    bcm2835_gpio_write(b, LOW);
}

#endif

