#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
*
* SPACE
* Avg: O(n) Worst: O(n)
* 
* ACCESS
* Avg: O(n) Worst: O(n)
*
* INSERT
* Avg: O(1) Worst: O(1)
*
* SEARCH
* Avg: O(n) Worst: O(n)
*
* DELETE
* Avg: O(1) Worst: O(1)
*
*/

typedef struct Dnode
{
    int data;
    struct Dnode* prev;
    struct Dnode* next;
} Dnode;

Dnode* createSnode (int value)
{
    Dnode* newNode = malloc(sizeof(Dnode));
    newNode->data = value;
    newNode ->prev = NULL;
    newNode ->next = NULL;
}

//function to push node to queue
void push(Dnode **head, Dnode **tail, int value)
{
    //create a new node
    Dnode *newNode = createSnode(value);
    //if the head is null (the linked list is empty)
    if (*head == NULL)
    {
        //set the head and the tail to be equal to the new node
        *head = newNode;
        *tail = newNode;
      return;
    }
    //set thhe newNode -> next to be the head (putting it at the front of the list)
    newNode->next = *head;
    (*head)->prev = newNode;
    //change the head (pointer to front of list) to the newNode
    *head = newNode;
}

//function to pop node from queue
void pop(Dnode **head, Dnode **tail)
{
    //create a temp node(for trtaversal w/o losing head)
    Dnode *temp = *head;
    //if the head is null(thereis no linked list)
    if (*head == NULL)
    {
        return;
    }
    //while the next node is not the tail
    while (temp->next != *tail)
    {
        //get the next node
        temp = temp->next;
    }
    //reset teh tail pointer to point to temp
    *tail = temp;
    //free the old stale tail
    free(temp->next);
    //set the new tail's -> next value to NULL
    temp->next = NULL;
}


//function to search through a queue (iterative)
Dnode* search(Dnode* head, Dnode* tail, int value)
{
    //if the head is null(the list does not exist)
    if(head == NULL)
    {
        //just return null
        return NULL;
    }
    //if the head is the value we are searching for
    if(head->data == value)
    {
        //return the head
         printf("FOUND %d\n", head->data);
        return head;
    }
    //same for the tail
    if(tail->data == value)
    {
         printf("FOUND %d\n", tail->data);
        return tail;
    }
    //while the next element is not null
    while(head->next != NULL)
    {
        //if the node is the value we are searching for
        if(head->data == value)
        {
            //return it
            printf("FOUND %d\n", head->data);
            return head;
        }
        else
        {
            //else move onto the next element
            head = head->next;
        }
    }
}

//function to print queue (iterative)
void printList(Dnode** head)
{
    Dnode* current = *head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current-> next;
    }
    printf("\n");
}



int main(int argc, char const *argv[])
{
    Dnode* head = NULL;
    Dnode* tail = NULL;
    push(&head, &tail, 20);
    push(&head, &tail, 30);
    push(&head, &tail, 40);
    printList(&head);
    pop(&head, &tail);
    printList(&head);
    search(head, tail, 40);
    return 0;
}
