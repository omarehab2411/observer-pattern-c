#include "subscriber.h"

// destructor function
void _destroy(struct subscriber* ptrSubscriber)
{
	if (ptrSubscriber != NULL)
	{
		free(ptrSubscriber);
	}
	ptrSubscriber = NULL;
}

//subscriber constructor
subscriber* newSubscriber(void (*istriggered)(char*))
{   
	//create new subscriber
	subscriber* newsub = (subscriber*)malloc(sizeof(subscriber));
	
	//add callback function to the functon pointer
	newsub->isTriggered = istriggered;  

	return newsub;
}