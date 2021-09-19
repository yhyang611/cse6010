#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 29

//declare the variables
float exponent;
float coefficient;
int i; //loop index
//declare entries of matrix m, M^(-1) and b
double m11;
double m12;
double m21;
double m22;
double M11;
double M12;
double M21;
double M22;
double b1;
double b2;
//declare the functions
double sum(int n,double *pt);
double square(int n,double *pt);
double sumofxy(int n,double *pt1,double *pt2);



int main()
{
  // Define a data type of flying bird
    struct flyingbird{
      double bodymass;
      double maxspeed;
  };
  typedef struct flyingbird Bird;
  // allocate enough space to be filled with raw data
  Bird *bird = (Bird *)malloc(N*sizeof(Bird));

  //Input body mass and max speed of bird using a structed pointer
  Bird data[2*N]={0.0965,64,0.947,82.08,1.14,105,0.058,91.8,4.2635,129,0.0075,40.32,1.11,195,0.0044,56.16,2.641,185,
  0.3545,136.8,6.75,135,6.05,67.68,9.35,88,8.19,127,0.78,110,1.5,153,4.49,90,0.096,170,1.02,129,3,100,0.366,83.52,0.088,46.8,
  10.55,80,9.52,82.08,0.0087,43.2,3.869,142,2.07,113,3.51,127,0.0646,56.33};
	
  bird = &data;
  
   // allocate enough space to be filled with log data
   Bird *logbird = (Bird *)malloc(N*sizeof(Bird));

   //Covert the variables by taking their logs
	for(i=0;i<N;i++)
	{
		(logbird+i)->bodymass=log((bird+i)->bodymass);
		(logbird+i)->maxspeed=log((bird+i)->maxspeed);
	}
	
	//Calculate the matrix entries needed for solving Mk=b
	m11 = N;
	m12 = sum(N,&(logbird->bodymass));
	m21 = m12;
	m22 = square(N,&(logbird->bodymass));
	b1 = sum(N,&(logbird->maxspeed));
	b2 = sumofxy(N,&(logbird->bodymass),&(logbird->maxspeed));
	
	//Calculate the entries of M-1
	M11 = m22/(m11*m22-m12*m21);
	M12 = -m12/(m11*m22-m12*m21);
	M21 = -m21/(m11*m22-m12*m21);
	M22 = m11/(m11*m22-m12*m21);

  //Solve k=M^(-1)b using matrix multiplication
	coefficient = exp(b1*M11+b2*M12);
	exponent = b1*M21+b2*M22;
	
	printf("The power law exponent is %.3f and the coefficient is %.3f\n", exponent, coefficient);
 
   return 0;
}

//Define the sum function
	double sum(int n,double *pt)
    {
     double add = 0;
     for(i=0; i<n; i++)
     {
       add += *(pt+i*2);
     }
     return add;
    }

//Define the square sum function
	double square(int n,double *pt)
    {
     double add = 0;
     for(i=0; i<n; i++)
     {
       add += (*(pt+i*2))*(*(pt+i*2));
     }
     return add;
    }

//Define the sum of xi*yi function
	double sumofxy(int n,double *pt1,double *pt2)
    {
     double add = 0;
     for(i=0; i<n; i++)
     {
       add += (*(pt1+i*2))*(*(pt2+i*2));
     }
     return add;
    }
