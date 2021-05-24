#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
/*
INSERTION SORT
Time: Best: O(n) Avg: O(n^2) Worst: O(n^2)
Space: O(1)

Take an index and sort it based on all the sorted indeces before it
EX
given array
4 3 2 10 12 1 5 6
put 3 where it belongs
3 4 2 10 12 1 5 6
put 2 where it belongs
2 3 4 10 12 1 5 6
10 is correct, continue
2 3 4 10 12 1 5 6
12 is correct, continue
2 3 4 10 12 1 5 6
put 1 where it belongs
1 2 3 4 10 12 5 6
put 5 where it belongs
1 2 3 4 5 10 12 6
put 6 where it belongs
1 2 3 4 5 6 10 12
array is sorted

*/
void printList(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void insertionSort(int *arr, int n)
{
    int i, j, key;
    //starting at the second element in the array
    for (i = 1; i < n; i++)
    {
        //set element = to key
        key = arr[i];
        //decrement j
        j = i - 1;
        //while j is greater than zero and the element at arr[j] is larger than the key
        while (j >= 0 && arr[j] > key)
        {
            //move one position ahead of current position
            arr[j + 1] = arr[j];
            //decrement j
            j--;
        }
        //set the moved value to the key
        arr[j + 1] = key;

        printList(arr, n);
    }
}
void insertionSortRec()
{
}

/*
SELECTION SORT
Time: Best: O(n^2) Avg: O(n^2) Worst: O(n^2)
Space: O(1)

Find the lowest value in the array, swap it with the first element
repear finding lowest element and swap with the next unswapped index
EX
given array
4 3 2 10 12 1 5 6
sawp 1 with first index
1 3 2 10 12 4 5 6
swap 2 with 3
1 2 3 10 12 4 5 6
leave 3 where it is
1 2 3 10 12 4 5 6
swap 4 with 10
1 2 3 4 12 10 5 6
swap 5 with 12
1 2 3 4 5 10 12 6
swap 6 with 10
1 2 3 4 5 6 12 10
swap 10 with 12
1 2 3 4 5 6 10 12
array is sorted

*/
//helper function to swap two pointers into eachothers spot
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int *arr, int n)
{
    //create i, j, and minimum index var
    int i, j, minIdx;
    //for the length of the list
    for (i = 0; i < n; i++)
    {
        //set min index to be first available index (by default)
        minIdx = i;
        //for every other node
        for (j = i + 1; j < n; j++)
        {
            //if the value at j is less than the value at minIdx
            if (arr[j] < arr[minIdx])
            {
                //update minimum index to be j
                minIdx = j;
            }
        }
        //swap the leftmost (unsorted) element with the minimum element we found
        swap(&arr[minIdx], &arr[i]);
    }
}

/*
BUBBLE SORT
Time: Best: O(n) Avg: O(n^2) Worst: O(n^2)
Space: O(1)

EX
given array
4 3 2 10 12 1 5 6
FIRST PASS
swap 4 and 3
3 4 2 10 12 1 5 6
swap 4 and 2
3 2 4 10 12 1 5 6
keep 4 and 10 in same positions
3 2 4 10 12 1 5 6
keep 10 and 12 in same positions
3 2 4 10 12 1 5 6
swap 12 and 1
3 2 4 10 1 12 5 6
swap 12 and 5
3 2 4 10 1 5 12 6
swap 12 and 6
3 2 4 10 1 5 6 12
FIRST PASS COMPLETE

you then would continue to make passes over the array until 
the array returns with no swaps
*/
void bubbleSort(int *arr, int n)
{
    //creating vars for the loops
    int i, j;
    //creating a boolean to see if we swapped this round (to exit early if possible)
    bool swapped;
    //for the length of the array
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        //for the length of teh unsorted array
        for (j = 0; j < n - i - 1; j++)
        {
            //if the current value is greater than teh next value
            if (arr[j] > arr[j + 1])
            {
                //swap them
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}
void bubbleSortRec(int* arr, int size)
{//base case
    if(size == 1)
    {
        return;
    }
    //for all elements in the array
    for(int i = 0; i < size-1; i++)
    {
        //if an element is larger than the element in front of it
        if(arr[i] > arr[i + 1])
        {
            //swap them
            swap(&arr[i], &arr[i + 1]);
        }
    }
    //call bubble sort on the remainder of the list
    bubbleSortRec(arr, size - 1);
}

/*
MERGE SORT
Time: Best: O(n logn) Avg: O(n logn) Worst: O(n logn)
Space: O(n)
Merge sort takes in an array and divides it into 2 smaller arrays
Merge sort then sorts those arrays, and then merges them back together
EX
given array
4 3 2 10 12 1 5 6
separate into 2 arrays
4 3 2 10     12 1 5 6
Sort the two arrays
2 3 4 10     1 5 6 12
merge them back together, by comparing the smallest element in each
array and adding it to the merged array

*/
//helper function for merge sort iteratively
int min(int x, int y)
{
    return (x < y) ? x : y;
}
void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    //getting the size of the left half
    int n1 = mid - left + 1;
    //getting the size of the right half
    int n2 = right - mid;

    //creating temp arrays for teh left and right halves of the list we are sorting
    int L[n1];
    int R[n2];

    //copy the values over from the unsorted array into the separate arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }
    //reset the values to zero and set k to the left of the list
    i = 0;
    j = 0;
    k = left;
    //while we have not filly travelled through either our L array or our R array
    while (i < n1 && j < n2)
    {
        //if the element in the L array is <= teh element in the R array
        if (L[i] <= R[j])
        {
            //merge the element from the L array
            array[k] = L[i];
            i++;
        }
        //else merge the element from the right array
        else
        {
            array[k] = R[j];
            j++;
        }
        //increment the merged array counter
        k++;
    }
    //to add any remaining values from the L array
    //(in the event the R array finished first)
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    //to add any remaining values from the R array
    //(in the event the L array finished first)
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortRec(int *array, int left, int right)
{
    //if the left index is less than the right index
    if (left < right)
    {
        //get the midpoint
        int mid = left + (right - left) / 2;
        //call mergesort on the left half of the array
        mergeSortRec(array, left, mid);
        //call mergesort on the right half of the array
        mergeSortRec(array, mid + 1, right);
        //merge the two halves back together
        merge(array, left, mid, right);
    }
}
void mergeSort(int *array, int size)
{
    //get an int to hold the current size
    int currentSize;
    //an int to hold the left side of the array
    int leftStart;
    //while we are at the second element to the last element
    for (currentSize = 1; currentSize <= size - 1; currentSize = 2 * currentSize)
    {   
        //from the left to the right side
        for (leftStart = 0; leftStart < size - 1; leftStart += 2 * currentSize)
        {
            //create a mid point
            int mid = min(leftStart + currentSize - 1, size - 1);
            //create the end of the array
            int rightEnd = min(leftStart + 2 * currentSize - 1, size - 1);
            //merge the two halves back together
            merge(array, leftStart, mid, rightEnd);
        }
    }
}


/*
QUICK SORT
Time: Best: O(n logn) Avg: O(n logn) Worst: O(n^2)
Space: O(log n)

quick sort is tricky, it works around pivots
much like merge sort, quicksort splits the array into multiple pieces
the key difference however, is that while merge sort divides the array equally into halves,
quicksort creates two arrays based on the pivot's value (usually the last element)
quicksort compares a given index value to teh pivot, and adds it to one array if the number is less than
the pivot, and to another array if the element is greater than the pivot
*/
//helper function for quicksort
int partition(int *array, int low, int high)
{
    //creating the pivot of the table
    int pivot = array[high];
    //setting i to the before the lowest element
    int i = (low - 1);
    //from the first element to the last element
    for (int j = low; j <= high; j++)
    {
        //if the value at index j is less than the pivot
        if (array[j] < pivot)
        {
            //increment i
            i++;
            //swap indexes i and j
            swap(&array[i], &array[j]);
        }
    }
    //swap teh pivot and the i + 1 value
    swap(&array[i + 1], &array[high]);

    return(i + 1);
}
void quicksortRec(int *array, int low, int high)
{
    //if low is less than high
    if(low < high)
    {
        //set the partition index using the partition function
        int partitionIndex = partition(array, low, high);
        //quicksort the left and the right side of the pivot
        quicksortRec(array, low, partitionIndex -1);
        quicksortRec(array, partitionIndex + 1, high);
    }
}
void quicksort(int* array, int low, int high)
{
    //create an auxiliary stack
    int stack[high - low + 1];
    //initialize top of stack
    int top = -1;
    //push initial low and high values to the stack
    stack[++top] = low;
    stack[++top] = high;
    //keep popping things from the stack while it is not empty
    while(top >= 0)
    {
        high = stack[top--];
        low = stack[top--];
    }
    //set teh pivot element at its correct position int he sorted array
    int p = partition(array, low, high);
    //if there are elements on the left side of the pivot
    //push to the left side of the stack
    if(p - 1 > low)
    {
        stack[++top] = p + 1;
        stack[++top] = high;
    }
    //if elements are on the right side of the pivot
    //push to the right side of the stack
    if(p + 1 < high)
    {
        stack[++top] = p + 1;
        stack[++top] = high;
    }
}



int main(int argc, char const *argv[])
{
    int *array10 = malloc(8 * sizeof(int));
    for(int i = 1; i < 8; i++)
    {
        scanf("%d\n", &array10[i]);
    }
    printList(array10, 8);
    insertionSort(array10, 8);
    printList(array10, 8);
    return 0;
}
