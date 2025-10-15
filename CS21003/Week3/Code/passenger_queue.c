/*
   Author: Miles Pallett
   Student ID number: 2584601
   Module Code: CS12003
*/


#include <stdlib.h> // required for some memory allocation functions such as 'malloc()' and 'free()'
#include <string.h> // you will need this if you use the string helper functions in C
#include "passenger_queue.h" // required, to include the Passenger Queue data structures, #defines, and function declarations
#include <stdio.h> // for displaying items in the queue

/*** ### FUNCTION IMPLEMENTATIONS ### ***/

/**
 * Create a new, empty queue, returning a pointer to the newly allocated
 * queue OR a value of NULL in the event of error.
 */
//CODE BASED ON AND ADAPTED FROM THE stack.c FILE PROVIDED IN THE StackSampleCode FOLDER
PassengerQueue *createQueue()
{
   //Declare temporary variable to store pointer to the stack
   PassengerQueue *pQueue = NULL;

   //Allocate memory for the new data using malloc
   pQueue = (PassengerQueue*)malloc(sizeof(PassengerQueue));

   //Check if a failure occured in memory allocation
   if (pQueue == NULL){
      return NULL; //return NULL letting basic_tester.c know an error has occured
   }

   //Initialise PassengerQueue fields to default values
   pQueue->head = NULL;
   pQueue->tail = NULL;

   //Return the pointer to the new queue
   return pQueue;
}

// add implementations of other functions here too, e.g., addPassenger(), removePassenger(), etc.