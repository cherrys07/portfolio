#include "buffer.h"

int iCounter;

/* declare buffer and three semaphores */
pthread_mutex_t mutex;
sem_t full, empty;
buffer_item buffer[BUFFER_SIZE];


void InitializeData()
{
	 pthread_mutex_init(&mutex , NULL);
	 sem_init(&full , 0 ,0);
	 sem_init(&empty , 0 , BUFFER_SIZE);
	 
	 iCounter = 0;
}

void * producer(void * param)
{
	/* create a variable for a randomly generated buffer item */
	 buffer_item item;
	 
	 while(TRUE)
	 {
	 	 /* sleep for a period of time */	
		  sleep(1);
		  
		  /* generate a random number */	
		  item = rand() / RAND_DIVISOR;
		  sem_wait(&empty);
		  pthread_mutex_lock(&mutex);
		  
		  /* insert the item into the buffer using the insert_item 
        	     method */
		  int iMsg = insert_item(item);
	  
		  if(iMsg == -1)
		  {
		   	printf("Error Inserting Item \n");
		  }
		  else
		  {
		   	printf("Produced Item :: %d  Thread No :: %d\n", item , *((int *)param));
		  }
		  
	  	  pthread_mutex_unlock(&mutex);
	  	  sem_post(&full);
	  
 	}
}

void * consumer(void * param)
{
	/* create a variable for a randomly generated buffer item */
	buffer_item item;

	while(TRUE)
	 {
	 	  /* sleep for a period of time */
		  sleep(1);
		  sem_wait(&full);
		  pthread_mutex_lock(&mutex);
		  
		  /* remove an item from the buffer using the remove_item
    		     method */
		  int iMsg = remove_item(&item);
		  
		  if(iMsg == -1)
		  {
		   	printf("Error Removing Item \n");
		  }
		  else
		  {
		   	printf("Consumed Item :: %d  Thread No :: %d \n", item ,*((int *)param));
		  }
		  
		  pthread_mutex_unlock(&mutex);
		  sem_post(&empty);
	  
	 }
	 
}

int insert_item(int item)
{
   
	 if(iCounter < BUFFER_SIZE)
	 {
		buffer[iCounter] =  item;
		iCounter++;
	  	return 1;
	 }
	 else
	 {
	  	return -1;
	 }
	
	
}

int remove_item(int *item)
{

	 if(iCounter > 0)
	 {
	  	*item = buffer[(iCounter - 1)];
	  	iCounter--;
	  	return 1;
	 }
	 else
	 {
	  	return -1;
	 }
		
}
