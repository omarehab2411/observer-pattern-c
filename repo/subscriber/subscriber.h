#pragma once
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "common.h"

typedef struct subscriber
{

	// destructor function
	void (*destroy) (struct subscriber*);

	//actual function to be triggered
	void (*isTriggered) (char*);

}subscriber;

//subscriber constructor
subscriber* newSubscriber(void (*istriggered)(char*));

#endif // SUBSCRIBER_H
