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

/**
 * Add a new passenger to the front or end of the queue depending on priority, 
 * returning either SUCCESS or a relevant error code.
 */
int addPassenger(PassengerQueue* qPtr, int passengerID, char passengerName[], int isPriority)
{
   //check if pointer input is valid.
   if (qPtr == NULL){
      return INVALID_INPUT_PARAMETER; //return error code if pointer is still set to NULL.
   }

   //check if passengerID input is within valid range.
   if ((passengerID < 1) || (passengerID > 88801)){
      return INVALID_INPUT_PARAMETER; //return error code if passengerID is outside the acceptable range.
   }

   //check if passengerName is of acceptable length.
   int passengerNameLength = strlen(passengerName);
   if (passengerNameLength > MAX_PASSENGER_NAME_LENGTH){
      return INVALID_INPUT_PARAMETER; //return error code if length of passengerName is greater than the maximum acceptable name length.
   }

   //check if the priority is set to either 1 or 0
   if ((isPriority < 0) || (isPriority > 1)){
      return INVALID_INPUT_PARAMETER;  //return error code [SHOULDNT HAPPEN AS PRIORITY VALUES ARE HARD CODED IN basic_tester.c]
   }

   //create pointer to new passenger and allocate its memory space
   Passenger *newPassenger = NULL;
   newPassenger = (Passenger*)malloc(sizeof(Passenger));

   //Check if memory allocation was succesfull and if not, return error code.
   if (newPassenger == NULL){
      return MEMORY_ALLOCATION_ERROR;
   }

   //Initialise the fields of the passenger with the inputs given, with the 'next' field defaulted to NULL.
   newPassenger->next = NULL;
   newPassenger->ID = passengerID;
   strcpy(newPassenger->name, passengerName);

   //Check if queue is empty, if so assign new data as both head and tail of queue
   if ((qPtr->tail == NULL) || (qPtr->head == NULL)){
      qPtr->tail = newPassenger;
      qPtr->head = newPassenger;
   }
   //Check if it should be added to the end of the queue
   else if (isPriority == 0){
      qPtr->tail->next = newPassenger; //Set 'next' field of current tail to the new node
      qPtr->tail = newPassenger; //Set new node as the new tail of the queue
   }
   //Check if it should be added to the start of the queue
   else if (isPriority == 1){
      newPassenger->next = qPtr->head; //Set 'next' field of new node to the current head of queue
      qPtr->head = newPassenger; //Set new node as the new head of the queue
   }

   return SUCCESS;
}

/**
 * Check through each node in the provided queue and return a 
 * count of the number of nodes within.
 */
int getPassengerCount(PassengerQueue* qPtr)
{
   //Check if queue provided is empty and if so, return a value of zero
   if (qPtr == NULL){
      return 0;
   }

   //Create a pointer to the passanger at the head of the queue
   Passenger *currentPassenger = qPtr->head;
   int count=1;

   //Move to the next passenger in the queue, iterating the count each time, until the end of the queue is reached
   do{
      currentPassenger = currentPassenger->next;
      count++;
   }while (currentPassenger->next != NULL);
   
   return count;
}

/**
 * Assign the head of the queue to a provided pointer, returning 
 * either SUCCESS or an appropriate error message
 */
int peekAtHeadPassenger(PassengerQueue *qPtr, Passenger *p)
{
   //Check if queue is empty and if so return an error message
   if (qPtr == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //Assign the given Passenger pointer to the head of the queue
   p->ID = qPtr->head->ID;
   strcpy(p->name, qPtr->head->name);
   p->next = qPtr->head->next;
   
   return SUCCESS;
}

/**
 * Assign the values of the head of the queue to a provided pointer, 
 * then remove the head of the queue, free its memory allocation, 
 * and reassign the head of the queue to the next node in the queue.
 */
int removePassengerAtHead(PassengerQueue* qPtr, Passenger *p)
{
   //If queue is empty, return error message
   if (qPtr == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //assign values from head of queue to provided pointer
   p->ID = qPtr->head->ID;
   strcpy(p->name, qPtr->head->name);
   p->next = qPtr->head->next;

   //assign head of queue to a temporary pointer
   Passenger *toRemove = qPtr->head;

   //assign head position of queue to next node in the queue
   qPtr->head = qPtr->head->next;

   //free the allocated memory from the node which has been removed
   free(toRemove);

   return SUCCESS;
}

/**
 * Assign the values of the tail of the queue to a provided pointer,
 * then remove the tail of the queue, free its memory allocation,
 * and reassign the tail of the queue to the previous node in the queue.
 */
int removePassengerAtTail(PassengerQueue* qPtr, Passenger *p)
{
   //If queue is empty, return error message
   if(qPtr == NULL){
      return INVALID_INPUT_PARAMETER;
   }

   //assign values from tail of queue to provided pointer
   p->ID = qPtr->tail->ID;
   strcpy(p->name, qPtr->tail->name);
   p->next = qPtr->tail->next; //(NULL)

   //assign tail of the queue to a temporary pointer
   Passenger *toRemove = qPtr->tail;

   //assign tail position of queue to previous node in the queue
   Passenger *currentPassenger = qPtr->head;

   while (currentPassenger->next != qPtr->tail){
      currentPassenger = currentPassenger->next;   //should find the node before the tail in the queue
   }

   currentPassenger->next = NULL;
   qPtr->tail = currentPassenger;

   //free the allocated memory from the node which has been removed
   free(toRemove);

   return SUCCESS;
}