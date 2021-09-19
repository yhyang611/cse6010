#include <stdio.h>
#include <math.h>
#define N 29

//declare the variables
float exponent;
float coefficient;
double x[100];
double y[100];
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

//Define the sum function
	double sum(int n,double item[100])
    {
     double add = 0;
     for(i=0; i<n; i++)
     {
       add += item[i];
     }
     return add;
    }

//Define the square sum function
	double square(int n,double item[100])
    {
     double add = 0;
     for(i=0; i<n; i++)
     {
       add += item[i]*item[i];
     }
     return add;
    }

//Define the sum of xi*yi function
	double sumofxy(int n,double itemx[100],double itemy[100])
    {
     double add = 0;
     for(i=0; i<n; i++)
     {
       add += itemx[i]*itemy[i];
     }
     return add;
    }

int main()
{
	//Input body mass and max speed of bird
	double bodymass[N]={0.0965,0.947,1.14,0.058,4.2635,0.0075,1.11,0.0044,2.641,0.3545,6.75,6.05,9.35,8.19,0.78,1.5,4.49,0.096,1.02,3,0.366,0.088,10.55,9.52,0.0087,3.869,2.07,3.51,0.0646};
	double maxspeed[N]={64,82.08,105,91.8,129,40.32,195,56.16,185,136.8,135,67.68,88,127,110,153,90,170,129,100,83.52,46.8,80,82.08,43.2,142,113,127,56.33};
	
	//double bodymass[N]={10,20,30,40,50,60,70,80};
	//double maxspeed[N]={123,234,345,456,567,678,789,890};
	
//for(i=0;i<N;i++){
    //printf("Please enter the body mass of the No.%d flying bird:\n",i+1);
    //scanf("%lf",&((bird+i)->bodymass));
    //printf("Please enter the max speed of the No.%d flying bird:\n",i+1);
    //scanf("%lf",&((bird+i)->maxspeed));
  //}

	//Covert the variables by taking their logs
	for(i=0;i<N;i++)
	{
		x[i]=log(bodymass[i]);
		y[i]=log(maxspeed[i]);
	}
	
	//Calculate the matrix entries needed for solving Mk=b
	m11 = N;
	m12 = sum(N,x);
	m21 = m12;
	m22 = square(N,x);
	b1 = sum(N,y);
	b2 = sumofxy(N,x,y);

	printf("%f\n",m12);
	
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