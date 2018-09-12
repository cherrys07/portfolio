

## Overview
This is a solution to the classic bounded-buffer problem using two producers and one consumer process. For this solution, counting semaphores are used for empty and full, and a mutex lock to represent mutex. The consumer and producer will run as separate threads to move items to and from the buffer that is synchronized with the empty, full, and mutex structures. The problem is solved with the use of a Pthread API.

## Description
The solution consists of a header file that contains important information for the size of the buffer, the required number of producer and consumer threads, a random divisor, and a fixed-sized array of type buffer_item. The array of buffer_item objects are used as a circular queue, along with one consumer and two producer threads to call the functions insert_item () and remove_item () to manipulate the buffer. The Pthread API uses the functions pthread_mutex_t, pthread_mutex_init, pthread_mutex_lock (), and pthread_mutex_unlock () to create and set a mutex to protect the critical section. Moreover, two semaphores called full and empty are created in the program to only be shared by threads belonging to the same process that created it. Furthermore, the rand () function is used in this program in which the producer thread will sleep for a random period of time and insert an integer into the buffer.  Moreover, the consumer thread will sleep for a random period of time and upon awakening it will attempt to remove the item from the buffer.
The main () function for this program will initialize the buffer and create one consumer and two producer threads. After the consumer and producer threads are created the main () function will sleep for a period of time and then, awaken to terminate the program.

### Usage
```
$ g++ -o main main.cpp  -lpthread 
$ ./main 
```
