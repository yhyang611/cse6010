/*
Simple heap implementation using an array with functions
Variables are global to avoid dealing with pointers
Recursive heapify functions
*/
#include <stdio.h>
#define MAXHEAPSIZE 20
int HeapInsert(int item);
int HeapDelete();
int PrintHeap();
int HeapifyDownRecursive(int i);
int HeapifyUpRecursive(int i);

// global variables for heap
int heapSize = 0; // number of elements in heap
int heap[MAXHEAPSIZE];

int main()
{
	int j, valReturned;
	
	HeapInsert(6);
	HeapInsert(9);
	HeapInsert(3);
	HeapInsert(2);
	HeapInsert(7);
	HeapInsert(4);
	HeapInsert(3);
	HeapInsert(8);
	
	PrintHeap();

	valReturned = HeapDelete();
	printf("deleted value is = %d\n",valReturned);
	
	PrintHeap();

	valReturned = HeapDelete();
	PrintHeap();
	valReturned = HeapDelete();
	PrintHeap();
	valReturned = HeapDelete();
	PrintHeap();
	valReturned = HeapDelete();
	PrintHeap();
	
	return 0;
}

// function to push an element onto the heap
int HeapInsert(int item)
{
{
		if(   )  // COMPLETE condition to ensure heap not full
		{

			// COMPLETE body; see lecture notes

			return 0;
		}
		else 
		{
			printf("Insertion error; heap is full\n");
			return 1;
		}
}
}

// function to delete an element from the heap
int HeapDelete()
{
	if(    )		// COMPLETE condition to ensure heap not empty
	{
		int returnValue;
		returnValue =    ;			// COMPLETE

		// COMPLETE remainder of function; see lecture notes
		
		return(returnValue);
	}
	else
	{
		printf("Deletion error; heap is empty\n");
		return -1;
	}
}
}

// function to print out heap elements
int PrintHeap()
{

	// COMPLETE
	
}

// Heapify Up function used when inserting
// recursive version
int HeapifyUpRecursive(int i)
{
	int temp;
	if (     )		// COMPLETE condition indicating this is the root
		return 0;
	if (     )		// COMPLETEthis node < its parent
	{
		// COMPLETE including recursive function call
	}
	return 0;
		
}

// Heapify Down function used when deleting
// recursive version
int HeapifyDownRecursive(int i)
{
	int temp;
	// if i exceeds heapsize or if no child nodes
	if (    ) // COMPLETE condition described above
		return 0;
	else if (    ) // COMPLETE condition for one child node case
	{
		if(    )   // COMPLETE condition needed for swap with child
		{
			// COMPLETE swap
		}
	}
	
	if (   ) // COMPLETE check heap property
		return 0;
	if (  ) 		// COMPLETE left node < right
	{
		// COMPLETE swap
		// add recursive call, conditions needed?
	}
	else								// right node >= left
	{
		// COMPLETE swap
		// add recursive call, conditions needed?
	}
	return 0;
}
