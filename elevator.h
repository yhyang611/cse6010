#define capacity 18
#define Floors 20
#define stoptime 15
#define movePerFloorTime 3
#define N 10000

//Declare variables
int maxFloor1 = 0;
int maxFloor2 = 0;
int numofpassengers = 0;
int i,k = 0; //loop index in the main function
float *run_t;
float *ave_t;
float maxrunt = 0; //maximum totoal runing time
float minrunt = 0; //minimum total running time
float averunt = 0; //average total running time
float avet = 0; //average waiting time for each passenger

//Declare the functions
int ran(int n, int m);
//n is the maximum number that can be generated in this function, m is the minimum number that can be generated in this function
double max(double *a, int n); //n is the number of values to be compared/calculated, same below
double min(double *a, int n);
double mean(double *a, int n);
double comp(double a, double b);
int searchmin(double *a, int n);
int compare_function(const void *a,const void *b);
double run_time(int *a, int n);
double ave_wait_time(int *a, int n);
int *classification(int *a, int n1, int n2, int *p);
//n1 is the value that related to the categary; n2 is number of the values that need to be classified;


//Define a function to generate random numbers
int ran(int n, int m)
{
    return(rand() % (n-m+1) + m);
}

//Define a function to return the maximum value
double max(double *a, int n){
    double max = *a;
    for(int j=0;j<n;j++){
        if(*(a+j)>max)
            max = *(a+j);
    }
    return(max);
}

//Define a function to return the minimum value
double min(double *a, int n){
    double min = *a;
    for(int j=0;j<n;j++){
        if(*(a+j)<min)
            min = *(a+j);
    }
    return(min);
}

//Define the mean function
double mean(double *a, int n){
    double add = 0;
    for(int j=0;j<n;j++){
        add += *(a+j);
    }    
    double mean = add/n;
    return(mean);
}

//Define the function to compare two values
double comp(double a, double b){
    if(a >= b)
        return(a);
    else
        return(b);
}

//Define a function to search for the minimum value and return its position
int searchmin(double *a, int n){
    double min = *a;
    int No = 0;
    for(int j=0;j<n;j++){
        if(*(a+j)<min){
            min = *(a+j);
            No = j;
        }
    }
    return(No);
}

//Define a funtion to compare a list of integers
int compare_function(const void *a,const void *b) 
{
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}
//Define a function to calculate the time to complete the elevator run (assume the stop time on the ground floor is zero)
double run_time(int *a, int n)
{
    int t = 0;
    //Sort the array
    qsort(a, n, sizeof(int), compare_function);
    if ((*a) == (*(a+n-1))){
        t = (*a)*movePerFloorTime;
    }
    else{
        t = *(a+n-1)*movePerFloorTime+stoptime;//the overall moving time + the stop time at the lowest floor
        for(int j=1;j<n;j++){
            if(*(a+j)!=*(a+j-1)){
                if(*(a+j) == *(a+n-1)){
                    break;
                }
                else
                    t += stoptime;
            }
        }
    }
    return(t);
}

//Define a function to calculate the average time per passenger (assume people will get out of the elevator instantly)
double ave_wait_time(int *a, int n)
{
    //Sort the array
    qsort(a, n, sizeof(int), compare_function);

    double ave_t = 0;
    int t[18]={};
    t[0] = (*a)*movePerFloorTime;//the waiting time for the person leave on the lowest floor
    int overall_t = t[0];
    if ((*a) == (*(a+n-1))){
        ave_t = t[0];
    }
    else{
        for(int j=1;j<n;j++){
            if(*(a+j) == *(a+j-1)){
                t[j] = t[j-1];
            }
            else{
                t[j] = t[j-1] + (*(a+j)-*(a+j-1))*movePerFloorTime + stoptime;
            }
            overall_t += t[j]; 
        }
            ave_t = overall_t/n;
    }
    return(ave_t);
}

//Define a function to classific the passengers assigned to different elevators
int *classification(int *a, int n1, int n2, int *p){
    int *floorn = (int *)malloc(100*sizeof(int));
    //int floorn[100] = {0};
    int s = 0;
    for(int j=0;j<n2;j++){
        if(*(a+1+j*2) == n1){
            *(floorn+s) = *(a+j*2);
            s++;
        }
    }
    *p = s;
    return(floorn);
}