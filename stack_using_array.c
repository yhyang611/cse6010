/*
Simple stack implementation using an array
This particular code adds 5 elements corresponding to the loop index
*/
#include <stdio.h>

int main()
{
	const int maxStackSize = 100;
	int sp =  0; 	// COMPLETE initialization stack pointer; index of next empty array element
	int stack[ 5 ];   	// COMPLETE declaration; array used to hold stack
	int j; 	   		// loop index
	
	// push 5 elements to stack
	// make each element the value of the loop index
	for ( j=0;j<5;j++  ) 		// COMPLETE loop condition
	{
			stack[j]=j;		// COMPLETE loop body
	}
	
	// print out stack contents
	printf("stack contents\n");
	for ( j=0;j<5;j++  )    	// COMPLETE Loop condition
	{
		printf("stack[%d] = %d\n",j,stack[j]);
	}


	// pop from stack
	int popped;
	popped =  stack[4] ;  	// COMPLETE
	printf("removed %d from stack\n",popped);
	sp =  4  ;       // COMPLETE 
	
	// print out array
	printf("stack contents\n");
	for ( j=0;j<4;j++  ) 		// COMPLETE loop condition as above
	{
			printf("stack[%d] = %d\n",j,stack[j]);
	}	
	return 0;
}
