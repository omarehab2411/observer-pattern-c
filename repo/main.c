#include "subscriber.h"
#include "publisher.h"

//dummy data 
typedef struct sensors
{
	int readings;

}sensors;


//function to be triggered when publisher publish it's data 
void is_sensed_callback(void* news) {
	printf("callback1: %d\n", *(int*)news);
}

int main()
{
	//dummy sensor data for testing
	sensors sensor1;
	sensor1.readings = 50;

	//create a subscriber
	subscriber* subscriber1=newSubscriber(is_sensed_callback);

	//create a publisher
	publisher* publisher1 = newPUBLISHER(&sensor1);

	//make a subscriber subscribe to a publisher
	publisher1->registerSUBSCRIBERS(publisher1, subscriber1);

	//notify all subscribers with a message
	publisher1->notifySUBSCIRBERS(publisher1,&(sensor1.readings));

}


