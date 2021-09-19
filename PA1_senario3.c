#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"


int main(){
    //genertate time seeds for random numbers
    time_t seconds = time(NULL);
    srand((unsigned) seconds);
    printf("Senario 3:\n");

    for(maxFloor1=6;maxFloor1<15;maxFloor1++){
        double *run_t = (double *)malloc(N*sizeof(double));
        double *ave_t = (double *)malloc(N*sizeof(double));
        for(i=0;i<N;i++){
            //generate a random number of passengers
            numofpassengers = ran(capacity,1);
            //generate randomly selected destination floor for each passenger and assign them to the two elevators
            int floors[18][2]={};
            for (k=0;k<numofpassengers;k++){
                floors[k][0] = ran(Floors,1);
                if (floors[k][0]<=maxFloor1)
                    floors[k][1] = 1;
                else
                    floors[k][1] = 2;
                    //floor[k][1]=1 means the passenger is assigned to elevator1; floor[k][1]=2 means the passenger is assigned to elevator2
            }
            int *p1 = (int *)malloc(sizeof(int));
            int *p2 = (int *)malloc(sizeof(int));
            int *floor1 = classification(&floors[0][0],1,numofpassengers,p1);
            int *floor2 = classification(&floors[0][0],2,numofpassengers,p2);
            
            //Comapre the running time of the two elevators and the total run time is equal to the larger runing time of the two
            *(run_t+i) = comp(run_time(floor1,*p1),run_time(floor2,*p2));
            *(ave_t+i) = (ave_wait_time(floor1,*p1)*(*p1)+ave_wait_time(floor2,*p2)*(*p2))/numofpassengers;
            free(p1);
            free(p2);
        }
        maxrunt = max(run_t,N);
        minrunt = min(run_t,N);
        averunt = mean(run_t,N);
        avet = mean(ave_t,N);
        free(run_t);
        free(ave_t);
        
        printf("If the MaxFloor1 is %d:\n", maxFloor1);
        printf("The maximum time to complete the elevator run is %f\n", maxrunt);
        printf("The minimum time to complete the elevator run is %f\n", minrunt);
        printf("The average time to complete the elevator run is %f\n", averunt);
        printf("The average waiting time for each passenger is %f\n", avet);
    }
    return(0);
}