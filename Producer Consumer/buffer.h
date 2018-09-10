#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <pthread.h>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>


#define BUFFER_SIZE 5
#define N_PRODUCERS 2
#define N_CONSUMERS 1
#define RAND_DIVISOR 100000000
#define TRUE 1

typedef int buffer_item;

void InitializeData();
void *producer(void *);			/* the producer thread */
void *consumer(void *);			/* the consumer thread */
int insert_item(int);			/* insert an object into buffer */
int remove_item(int *);			/* remove an object from buffer */

	


#endif
