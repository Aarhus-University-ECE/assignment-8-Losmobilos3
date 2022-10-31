//extern "C" {
    #include <stdio.h>
    #include "insertion_sort.h"
    #include "linked_list.h"
    #include "list_queue.h"
    // Add the header files required to run your main 
//}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    printf("INSERTIONSORT: \n");

    linked_list* liste = createLinkedList();
    liste->head = createNode(10);
    node_t *T = liste->head;
    /*for (int i = 0; i < 4; i++)
    {
        T->next = createNode(9-i);
        T = T->next;
    }*/
        T->next = createNode(5);
        T = T->next;
        T->next = createNode(99);
        T = T->next;
        T->next = createNode(3);
        T = T->next;
        T->next = createNode(2);
        T = T->next;

    printLL(liste);

    sort(liste);

    printLL(liste);

    printf("\nQUEUE:\n");
    
    queue *q = malloc(sizeof(queue));
    init_queue(q);

    enqueue(q, 5);
    enqueue(q, 2);
    printf("%d \n", q->size);

    printf("%d \n", dequeue(q));
    printf("%d \n", dequeue(q));
    

    return 0;
}