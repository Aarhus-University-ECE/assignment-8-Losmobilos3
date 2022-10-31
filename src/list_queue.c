#include "list_queue.h"


void init_queue(queue *q)
{
  // Add your init_queue
  q->rear = malloc(sizeof(qnode)); // Creates a node in the rear 
  q->rear->next = NULL;            // The node contains NULL as the next node
  q->front = q->rear;              // q.front points at q->rear
  q->size = 0;                     // initalizes the size as 0, since it starts out empty
}

int empty(queue *q)
{
  if (q->size == 0) // If q.size = 0 it must be empty
    return 1;
  return 0;
  // Add your empty function  
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *T = q->rear->next; // Stores the old rear node
  q->rear->next = malloc(sizeof(qnode)); //
  q->rear->next->data = x;               // Makes a new node, and puts it behind the one before with the new given data.
  q->rear->next->next = T;               // 

  qnode *Ts = q->rear;     //
  while (Ts->next != NULL) // Updates q.front
    Ts = Ts->next;         //
  q->front = Ts;           //

  q->size++; // increments the size by 1 for each added element
}

int dequeue(queue *q)
{
  // Add your dequeue function
  assert(empty); // Checks if the queue is empty, if it is, abort.

  int value = q->front->data; // Takes the data from the element in the front of the queue

  qnode *T = q->rear;           // 
  while (T->next != q->front)   // Finds the next to be first element
    T = T->next;                //

  T->next = NULL; // removes the first element
  q->front = T;     // sets the next to be first element as the first element

  q->size--; // decrements the size after removing a node.

  return value;
}
