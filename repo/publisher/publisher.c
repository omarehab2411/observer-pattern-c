#include "publisher.h"

//destructor 
static void _destroy(struct publisher* publisher)
{
	if(publisher!=NULL)
	{
		free(publisher);
	}
	publisher = NULL;
}

//register subscribers function
int _registerSUBSCRIBERS(struct publisher* publisher, struct subscriber* subscriber)
{
	if(publisher->subscribersCount==MAX_SUBSCRIBERS-1)
		return 0;     //list is filled with subscribers
   
	int i = 0;
	while (publisher->subscribersList[i] != 0)
		i++;
	publisher->subscribersList[i] = subscriber;
	publisher->subscribersCount++;
	return 1; 
}

//unregister subscribers function
int _unregisterSUBSCRIBERS(struct publisher* publisher, struct subscriber* subscriber)
{
	for(int i=0;i<MAX_SUBSCRIBERS;i++)
	{
		if (publisher->subscribersList[i] == subscriber)
			publisher->subscribersList[i] = 0;
	}
	//decrease number of subscribers by one
	publisher->subscribersCount--;
}

//notify subscribers
void _notifySUBSCIRBERS(struct publisher* publisher, void* data)
{
	printf("Sending the message to the observers\n");
	for (int i = 0; i < MAX_SUBSCRIBERS; i++)
	{
		if (publisher->subscribersList[i] != 0)
		{
			publisher->subscribersList[i]->isTriggered(data);
			printf("====================================\n");
		}
	}
   
}

publisher* newPUBLISHER(void*data)
{
	publisher* newpub = (publisher*)malloc(sizeof(publisher));
	newpub->data = data;
	newpub->destroy = _destroy;
	newpub->notifySUBSCIRBERS = _notifySUBSCIRBERS;
	newpub->registerSUBSCRIBERS = _registerSUBSCRIBERS;
	newpub->unregisterSUBSCRIBERS = _unregisterSUBSCRIBERS;

	for (int i = 0; i < MAX_SUBSCRIBERS; i++)
		//init all fields with zeros
		newpub->subscribersList[i] = 0;
	    
	   //init subscribers counter 
	   newpub->subscribersCount = 0;
	return newpub;  //ptr to the publisher
}
