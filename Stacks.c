#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

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



/*
STACKS
Last in First out (like a stack of dishes)
Linear data structure
ACCESS: Avg: O(n) Worst: O(n)
SEARCH: Avg: O(n) Worst: O(n)
INSERTION: Avg: O(1) Worst: O(1)
DELETION: Avg: O(1) Worst: O(1)
SPACE: Worst: O(n)

typedef struct Stack
{
    int* array;
  	int top;
  	int size;
}Stack;

//function to check if stack is empty
bool isEmpty(Stack* stack)
{
    //when stack is empty 'top' is equal to -1
	return ((stack -> top) == -1);
}
//function to check if stack is full
bool isFull(Stack* stack)
{
  return (stack->top == stack->size -1);
}
//function to add to stack
void push(Stack* stack, int value)
{
    //if full dont add
  if (isFull(stack))
  {
    return;
  }
  else
  {
    //add to the top of the stack and increment top
    stack->array[++stack -> top] = value;
  }
}
//function to remove from stack
void pop(Stack* stack)
{
    //if stack is empty return
  if(isEmpty(stack))
  {
	return;
  }
  else
  {
      //else decrement top (we dont need to delete since the value in top +1 will be overwritten)
    --stack->top;
  }
}
//function to get val at top of stack
int peek(Stack* stack)
{
    //if stack is empty return
  if(isEmpty(stack))
  {
    return -1;
  }
  //return teh value at top of stack
  return stack->array[stack->top];
  
}
void printStack(Stack * stack)
{
    for(int i = 0; i <= stack ->top; i++)
    {
        printf("%d\t", stack->array[i]);
        
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    //creating memory for a new stack
    Stack* stack = malloc(sizeof(Stack));
    //setting size of stack
  	stack -> size = 10;
  	stack -> array = malloc(stack -> size * sizeof(int));
  	stack -> top = -1;
  	push(stack, 50);
    push(stack, 30);
    push(stack, 50);
    printStack(stack);
    pop(stack);
    printStack(stack);
    push(stack, 75);
    printStack(stack);
    int val = peek(stack);
    printf("%d\n", val);

  	
  
    return 0;
}
*/
//node structure
typedef struct Node
{
    char data;
    struct Node* prev;
    struct Node* next;
}Node;
//stack structure
typedef struct Stack
{
    Node* head;

}Stack;
//helper function to create node
Node* createNode(int val)
{
    //memory to create a new node
    Node* new = malloc(sizeof(Node));
    ///assigning values
    new->data = val;
    new->prev = NULL;
    new-> next = NULL;
}
//function to check if list is empty
bool isEmpty(Stack* stack)
{
    return (stack->head == NULL);
}
void push(Stack* stack, int val)
{
    Node* newNode = createNode(val);
    if(stack->head == NULL)
    {
        stack->head = newNode;
    }
    else
    {
    newNode->next = stack->head;
    stack-> head-> prev = newNode;
    stack->head = newNode;
    }
}
void pop(Stack* stack)
{
    Node* temp = stack-> head;
    stack-> head = stack -> head ->next;
    free(temp);
}
int peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    else
    {
        return (stack->head->data);
    }
}
void printStack(Stack* stack)
{
    Node* temp = stack->head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    Stack* newStack = malloc(sizeof(Stack));
    newStack -> head = NULL;
    push(newStack, 30);
    push(newStack, 40);
    push(newStack, 50);
    printStack(newStack);
    pop(newStack);
    printStack(newStack);
    int var = peek(newStack);
    printf("%d\n", var);
    return 0;
}
