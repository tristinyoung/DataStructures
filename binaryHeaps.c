#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct Heap
{
    int *array;
    int count;
    int cap;
    int heapType;
} Heap;
Heap *createHeap(int cap, int heapType);
void insert(int value, Heap *heap);
void bottomUpCorrection(Heap *heap, int index);
void topDownCorrection(Heap *heap, int parentNode);
void print(Heap *heap);
int popMin(Heap *heap);
int peek(Heap *heap);
//function to create a heap in memory
Heap *createHeap(int cap, int heapType)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->cap = cap;
    heap->heapType = heapType;
    heap->count = 0;
    heap->array = malloc(cap * sizeof(int));

    return heap;
}
//function to insert a valuie into the heap
void insert(int value, Heap *heap)
{
    //if we are under our capacity(if there is size)
    if (heap->count < heap->cap)
    {
        //set the next free array slot to be our new entry
        heap->array[heap->count] = value;
        //perform bottom up corrention to keep heap properties true
        bottomUpCorrection(heap, heap->count);
        //increase the count
        heap->count++;
    }
}
//returns the topmost element without popping it
int peek(Heap *heap)
{
    //if the heap is empty
    if (heap->count == 0)
    {
        return -1;
    }
    //assign an int to the first element of the ehap array 
    //(smallest element by default) and return it
    int peek = heap->array[0];
    return peek;
}
//pops the minimum value from the heap
int popMin(Heap *heap)
{
    int pop;
    //return if heap is empty
    if (heap->count == 0)
    {
        return -1;
    }
    //save value at heap index[0]
    pop = heap->array[0];
    //replace the minimumvalue in teh heap with the last element
    heap->array[0] = heap->array[heap->count - 1];
    //decrement count
    heap->count--;
    //correct from the top down to satisfy binary heap properties
    topDownCorrection(heap, 0);
    //return value just popped
    return pop;
}
//correction when inserting a value
void bottomUpCorrection(Heap *heap, int index)
{   //create a temp node and a parent node
    int temp;
    int parentNode = (index - 1) / 2;
    //if the parent nodes value is larger than the indexes value
    if (heap->array[parentNode] > heap->array[index])
    {
        //swap them and recursively call itself
        temp = heap->array[parentNode];
        heap->array[parentNode] = heap->array[index];
        heap->array[index] = temp;
        bottomUpCorrection(heap, parentNode);
    }
}
//correction when deleting minimum value
void topDownCorrection(Heap *heap, int parentNode)
{   
    //create a left, right, min, and temp vars
    int left = (parentNode * 2) + 1;
    int right = (parentNode * 2) + 2;
    int minimum;
    int temp;
    //if the left is greater than heap count or if it is smaller than zero
    if (left >= heap->count || left < 0)
    {
        //out of bounds so return -1
        left = -1;
    }
    //same fro right side
    if (right >= heap->count || right < 0)
    {
        right = -1;
    }
    //if left is valid & less than the parent node
    if (left != -1 && heap->array[left] < heap->array[parentNode])
    {
        //set the min to left
        minimum = left;
    }
    else
    {
        //set teh min to parent node
        minimum = parentNode;
    }
    //if teh right is valid and less than the parent node
    if (right != -1 && heap->array[right] < heap->array[minimum])
    {
        //set the minimum to right
        minimum = right;
    }
    //if thr minimmum is not the parent node (there is still corrections to be made)
    if (minimum != parentNode)
    {
        //swap the parent node and the minimum fiound
        temp = heap->array[minimum];
        heap->array[minimum] = heap->array[parentNode];
        heap->array[parentNode] = temp;
        //recursively call itself to keep sorting
        topDownCorrection(heap, minimum);
    }
}
void print(Heap *heap)
{
    for (int i = 0; i < heap->count; i++)
    {
        printf("%d\t", heap->array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Heap *heap = createHeap(20, 0);
    insert(20, heap);
    insert(40, heap);
    insert(30, heap);
    insert(15, heap);
    insert(2, heap);
    print(heap);
    popMin(heap);
    print(heap);
    return 0;
}
