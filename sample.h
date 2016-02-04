//
//  sample.h
//  
//
//  Created by Peter Tuerk on 3/3/15.
//
//
#include "../grom/GromOSAPI/GromOSAPI/GromApp.h"

class MyApp : public GromApp
{
public:
	void init();
	void run();
	void destroy();
	void message(GMessage *msg);
};
