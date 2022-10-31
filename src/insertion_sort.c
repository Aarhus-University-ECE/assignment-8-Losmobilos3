#include "insertion_sort.h"
#include "linked_list.h"

void sort(linked_list *llPtr)
{
    // Add your sort function here
    node_t *currentNode = llPtr->head; // Initialize starting node
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next; // selects next node to be sorted
        node_t *T = llPtr->head; // stores the new first element
        node_t *latestT = malloc(sizeof(node_t)); // a variable to know which element was sorted before
        node_t *lastUnsorted = llPtr->head;                                                     //
        while (lastUnsorted->next != NULL && lastUnsorted->data <= lastUnsorted->next->data)    //
        {                                                                                       // Stores the last element that has been sorted
            lastUnsorted = lastUnsorted->next;                                                  //
        }                                                                                       //


        while(T != currentNode)                   // Loops through all already sortede elements
        {
            if (currentNode->data < T->data && T == llPtr->head) //
            {                                                    //
                lastUnsorted->next = currentNode->next;          // If the smallest and thus first number is smaller than the
                llPtr->head = currentNode;                       // number currently being sorted. The number currently being 
                currentNode->next = T;                           // sorted will be put in before the first, and the head will now point to it
                break;                                           //
            }                                                    //
            else if (currentNode->data < T->data)           //
            {                                               //
                lastUnsorted->next = currentNode->next;     // Does the same as above, just with the variation that now the current
                latestT->next = currentNode;                // node being sorted won't be the first element.
                currentNode->next = T;                      //
                break;                                      //
            }
            latestT = T;              // Updates which number was last checked
            T = T->next;              // Updates the number which has just been checked
        }
    }
}
