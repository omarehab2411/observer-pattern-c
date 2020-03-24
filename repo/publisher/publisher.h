
#ifndef PUBLISHER_H
#define PUBLISHER_H
#include"subscriber.h"

typedef struct publisher
{    
	//pointer to data to be published later
	void* data;

	//destructor 
	void (*destroy) (struct publisher*);


	//array of pointers to every subscriber
	subscriber* subscribersList[MAX_SUBSCRIBERS];
    
	//register subscribers function
	int  (*registerSUBSCRIBERS) (struct publisher*,struct subscriber*);

	//unregister subscribers function
	int   (*unregisterSUBSCRIBERS) (struct publisher*, struct subscriber*);

	//notify subscribers
	void (*notifySUBSCIRBERS) (struct publisher*,void* data);

	int subscribersCount;

}publisher;
publisher* newPUBLISHER(void*);


#endif // !PUBLISHER_H
