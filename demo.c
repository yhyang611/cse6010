#include<stdio.h>
#include <stdlib.h>
#include <math.h>

/*
//Define the log of an array function
	double *logarray(int n, double* oldarray)
    {
     double* newarray;
     newarray=(double*) malloc(n*sizeof(double));
     for(int i=0; i<n; i++)
     {
       *(newarray+i)=log(*oldarray);
       oldarray++;
     }
     return &newarray;
     free(newarray);
    }
*/

/*
void fill_array(char *arry_to_be_filled, int arr_size){
    // loop over arry_to_be_filled
    for(int i=0; i<n; i++)
     {
       *(arry_to_be_filled+i)=log(*oldarray);
       oldarray++;
     }
}
*/


int main()
{
  int *p;
  int i=4;
  p=&i;
  *p=*p+1;
  printf("%d\n",*p);

 struct flyingbird{
      double bodymass;
      double maxspeed;
  };

  struct flyingbird birdtype;
  
  

// Define a data type of flying bird
  typedef struct flyingbird Bird;
  // allocate enough space to be filled
  Bird *bird = (Bird *)malloc(29*sizeof(Bird));
  
  (*(bird+1)).bodymass = 10;
  (*bird).bodymass = 9;
  (*(bird+1)).bodymass = 10;
  printf("%f\n",*(bird));
  printf("%f\n",*((bird+1)));

  // free in the same scope as malloc
   free(bird);  

}