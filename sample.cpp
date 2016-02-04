//
//  sample.cpp
//  
//
//  Created by Peter Tuerk on 3/3/15.
//
//

#include "sample.h"

void MyApp::init()
{
    //always runs first
	printf("Steve ran the init function");
}

void MyApp::destroy()
{
    //only runs on 'safe shutdown'
	printf("Steve ran the destroy function");
}

void MyApp::run()
{
	printf("Steve ran the run function");
    while(!shouldQuit())
    {
    }
}

void MyApp::message(GMessage *msg)
{
    printf("App Recieved [%i]\n", (short)msg->getBuffer()[0]);
/*    switch (*(short *)&msg->getBuffer()[0])
    {
        case GMT_PONG: //display interface
        {
        }
        case GMT_PICKLIST: //which button was pressed
        {
            if(WON)
            {
                shouldQuit = true;
            }
        }
    }
*/
}
