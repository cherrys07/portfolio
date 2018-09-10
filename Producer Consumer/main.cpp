#include "buffer.cpp"


int main(int argc , char * argv[])
{
	 /* initialize buffer */
	 InitializeData(); 
	 
	 pthread_t ProducerThread , ConsumerThread;
	 
	 /* create producer threads */
	 int *aa = new int [5];
	 for(int i = 1 ; i <= N_PRODUCERS ; i++)
	 {
		  aa[i] = i;
		  pthread_t t;
		  pthread_create(&t , NULL, producer , &aa[i]);
		  printf("Creating Producer %d \n", i);
	 }
	 
	 /*create consumer threads */
	 int *bb = new int[5];
	 for(int i = 1 ; i <= N_CONSUMERS ; i++)
	 {
		  bb[i] = i;
		  pthread_t t;
		  pthread_create(&t , NULL, consumer , &bb[i]);
		  printf("Creating Consumer %d \n", i);
	 }
	 
	 /* sleep */
	 sleep(5);
	 delete [] aa;
	 delete [] bb;
	 

 return 0;
}


