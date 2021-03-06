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
//struct for a node in a singly linked list
typedef struct Snode
{
    int data;
    struct Snode *next;
} Snode;

//helper function to allocate memory for a Snode
Snode *createSnode(int value)
{

    //creating memory for the node
    Snode *temp = (Snode*) malloc(sizeof(Snode));
    //assigning the value to the node we created
    temp->data = value;
    //setting next to null
    temp->next = NULL;
    //return the created node
    return temp;
}

//function to insert a node into a singly linked list in the front of the list (iterative)
void insertSnodeFirst(Snode **head, Snode **tail, int value)
{
    //create a new node
    Snode *newNode = createSnode(value);
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
    //change the head (pointer to front of list) to the newNode
    *head = newNode;
}

//function to insert a node into a singly linked list at the end of the list (iterative)
void insertSnodeLast(Snode **head, Snode **tail, int value)
{
    //create a new node
    Snode *newNode = createSnode(value);
    //if the head is null(the list is empty)
    if (*head == NULL)
    {
        //set the head and the tail to be equal to the newNode
        *head = newNode;
        *tail = newNode;
      return;
    }
    //set tail -> next to be the newNode (adding it to the end of the list)
    (*tail)->next = newNode;
    //update teh tail to the newNode(pointer to the end of the list)
    *tail = newNode;
}

//function to insert a node into a singly linked list at a specific index (iterative)
void insertSnodeAtIndex(Snode **head, Snode **tail, int value, int index)
{
    //create the newNode
    Snode *newNode = createSnode(value);
    //get a temp node to hold the head (so we can return head)
    Snode *current = *head;
    //if we are inserting at 0 index (at the front of the list)
    if (index == 0)
    {
        //perform insertSnodeFirst function
        insertSnodeFirst(head, tail, value);
      return;
    }
    //while the index is not 0
    while (index != 0)
    {
        //traverse one node down the singly linked list
        current = current->next;
        //if teh current node is null (we have reached the end of our list)
        if (current == NULL)
        {
            //add tot eh end of teh list like above
            (*tail)->next = current;
            *tail = current;
            return;
        }
        //decrement index
        index--;
    }
    //set the newNode -> next = be equal to the current -> next
    newNode->next = current->next;
    //setting current -> next to be equal to newNode
    current->next = newNode;

    //EX: BEFORE: CurrentNode --- NextNode (CurrentNode -> next = NextNode)
    //    AFTER: CurrentNode --- NewNode --- NextNode
    //              (CurrentNode -> next = NewNode, NewNode -> next = NextNode)
    
}

//function to delete the head node of a singly linked list (iterative)
void deleteShead(Snode **head)
{
    //if the head is null(the list is empty)
    if (*head == NULL)
    {
        //return NULL
        return;
    }
    //else create a temp node and assign it to head (so we can manipulate head w/o changing it)
    //set the temp node to equal head ->next
    Snode *temp = *head;
    //free the head
    *head = (*head)->next;
    free(temp);
}

//function to delete the tail of a singly linked list (iterative)
void deleteStail(Snode **head, Snode **tail)
{
    //create a temp node(for trtaversal w/o losing head)
    Snode *temp = *head;
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

//function to delete a node with a specific value (iterative)
void deleteSvalue(Snode **head, Snode **tail, int value)
{
    //set a new node to be equal to the head(for traversal)
    Snode *temp = *head;
    //if the head is the node we are looking for
    if ((*head)->data == value)
    {
        //delete the head using the deleteHead function and return the updated head
        deleteShead(head);
        return;
    }
    //same as above but for the tail
    if((*tail)->data == value)
  {
    deleteStail(head, tail);
    return;
  }
    //set a found pointer to null (to store the node we are searching for if we find it)
    Snode *found = NULL;
    //while the current nodes -> next -> next value is NOT null
    while (temp->next->next != NULL)
    {
        //if the value at temp -> next matches the value we are searching for
        if (temp->next->data == value)
        {
            //set the found pointer to equal temp
            found = temp;
            //break
            break;
        }
    }
    //if found is null (the node does not exist)
    if (found == NULL)
    {
        //return the head with no modifications
        return;
    }
    //else set a temp node to be the node after found
    Snode *temp1 = found->next;
    //update found -> next to be equal to the -> next -> next node
    found->next = found->next->next;
    //free the temp node
    free(temp1);
    //return the head of the modified list
    return;
}

//function to search through a singly linked list (iterative)
Snode* searchSnode(Snode* head, Snode* tail, int value)
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

//function to print linked list (iterative)
void printList(Snode** head)
{
    Snode* current = *head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current-> next;
    }
    printf("\n");
}

///function to insert a node into a singly linked list at a specific index (recursive)
void insertSnodeAtIndexRec(Snode** head, Snode** tail, int value, int index)
{
      // use recursion to navigate to the index
      printf("index: %d\n", index);
      if(index == 0)
      {
        insertSnodeAtIndex(head, tail, value, 0);
        printf("Terminated\n");
      }
      else {
        head = &((*head)->next);
        insertSnodeAtIndexRec(head, tail, value, index-1);
      }
      /*
    Snode* temp = *head;
	//base case
  while(index !=0)
  {
    index = index-1;
    temp = temp -> next;
    insertSnodeAtIndexRec(&temp, tail, value, index);
  }
  //base case down here
      // head --- head2 --- tail
      //head --- head2 --- newNode --- tail (head2->next = newnode, newNode->next = tail)
   Snode* newNode = createSnode(value);
   newNode -> next = temp -> next;
    temp-> next = newNode;
   if(temp == *tail)
   {
     *tail = newNode;
     
   }
   */
}




int main(int argc, char const *argv[])
{

    Snode *head = NULL;
    Snode *tail = NULL;
    insertSnodeFirst(&head, &tail, 30);
    insertSnodeFirst(&head, &tail, 20);
    insertSnodeFirst(&head, &tail, 70);
    insertSnodeFirst(&head, &tail, 50);
    insertSnodeAtIndexRec(&head, &tail, 40, 3);
    printList(&head);
    deleteStail(&head, &tail);
    printList(&head);
    deleteSvalue(&head, &tail, 70);
    printList(&head);
    Snode* target = searchSnode(head, tail, 50);
    return 0;
}

 