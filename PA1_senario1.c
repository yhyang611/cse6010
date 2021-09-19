#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"


int main(){
    //genertate time seeds for random numbers
    time_t seconds = time(NULL);
    srand((unsigned) seconds);
    
    double *run_t = (double *)malloc(N*sizeof(double));
    double *ave_t = (double *)malloc(N*sizeof(double));
    for(i=0;i<N;i++){
        //generate a random number of passengers
        numofpassengers = ran(capacity,1);
        //generate randomly selected destination floor for each passenger
        int floor[18]={};
        for (k=0;k<numofpassengers;k++){
            floor[k] = ran(Floors,1);
        }
        *(run_t+i) = run_time(floor,numofpassengers);
        *(ave_t+i) = ave_wait_time(floor,numofpassengers);
    }

    maxrunt = max(run_t,N);
    minrunt = min(run_t,N);
    averunt = mean(run_t,N);
    avet = mean(ave_t,N);
    printf("Senario 1:\nThe maximum time to complete the elevator run is %f\n", maxrunt);
    printf("The minimum time to complete the elevator run is %f\n", minrunt);
    printf("The average time to complete the elevator run is %f\n", averunt);
    printf("The average waiting time for every passenger is %f\n", avet);

    free(run_t);
    free(ave_t);
    return(0);
}