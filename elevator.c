#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"


int main(){
    //genertate time seeds for random numbers
    time_t seconds = time(NULL);
    srand((unsigned) seconds);
    // allocate enough space of totoal run time and average waiting time to be filled for N runs
    double *run_t = (double *)malloc(N*sizeof(double));
    double *ave_t = (double *)malloc(N*sizeof(double));
    
    /////////////////////// senario 1 ///////////////////////
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

    /////////////////////// senario 2 ///////////////////////
    for(i=0;i<N;i++){
        //generate a random number of passengers
        numofpassengers = ran(capacity,1);
        //generate randomly selected destination floor for each passenger and randomly assign them to an elevator
        int floors[18][2]={};
        for (k=0;k<numofpassengers;k++){
            floors[k][0] = ran(Floors,1);
            floors[k][1] = ran(2,1);
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
    printf("\nSenario 2:\nThe maximum time to complete the elevator run is %f\n", maxrunt);
    printf("The minimum time to complete the elevator run is %f\n", minrunt);
    printf("The average time to complete the elevator run is %f\n", averunt);
    printf("The average waiting time for each passenger is %f\n", avet);


    /////////////////////// senario 3 ///////////////////////
    printf("\nSenario 3:\n");
    for(maxFloor1=7;maxFloor1<15;maxFloor1++){
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
        
        printf("If the MaxFloor1 is %d:\n", maxFloor1);
        printf("The maximum time to complete the elevator run is %f\n", maxrunt);
        printf("The minimum time to complete the elevator run is %f\n", minrunt);
        printf("The average time to complete the elevator run is %f\n", averunt);
        printf("The average waiting time for each passenger is %f\n", avet);
        
    }


    /////////////////////// senario 4 ///////////////////////
    double *run_t1 = (double *)malloc(171*sizeof(double));
    double *ave_t1 = (double *)malloc(171*sizeof(double));
    int *floor1 = (int *)malloc(171*sizeof(int));
    int *floor2 = (int *)malloc(171*sizeof(int));
    int q = 0;

    for(maxFloor1=1;maxFloor1<19;maxFloor1++){
        for(maxFloor2=maxFloor1+1;maxFloor2<20;maxFloor2++){
            for(i=0;i<N;i++){
                //generate a random number of passengers
                numofpassengers = ran(capacity,1);
                //generate randomly selected destination floor for each passenger and assign them to the two elevators
                int floors[18][2]={0};
                for (k=0;k<numofpassengers;k++){
                    floors[k][0] = ran(Floors,1);
                    if (floors[k][0]<=maxFloor1)
                        floors[k][1] = 1;
                    else if(floors[k][0]<=maxFloor2)
                        floors[k][1] = 2;
                    else
                        floors[k][1] = 3;
                    //floor[k][1]=1 means the passenger is assigned to elevator1
                }
                int *p1 = (int *)malloc(sizeof(int));
                int *p2 = (int *)malloc(sizeof(int));
                int *p3 = (int *)malloc(sizeof(int));
                int *floor1 = classification(&floors[0][0],1,numofpassengers,p1);
                int *floor2 = classification(&floors[0][0],2,numofpassengers,p2);
                int *floor3 = classification(&floors[0][0],3,numofpassengers,p3);
                
                double *run_t2 = (double *)malloc(3*sizeof(double));
                *run_t2 = run_time(floor1,*p1); // total run time of the first evelvator
                *(run_t2+1) = run_time(floor2,*p2);
                *(run_t2+2) = run_time(floor3,*p3);
                *(run_t+i) = max(run_t2,3);
                *(ave_t+i) = (ave_wait_time(floor1,*p1)*(*p1)+ave_wait_time(floor2,*p2)*(*p2)+ave_wait_time(floor3,*p3)*(*p3))/numofpassengers;
                free(p1);
                free(p2);
                free(p3);
                free(run_t2);
            }
            *(run_t1+q) = mean(run_t,N);
            *(ave_t1+q) = mean(ave_t,N);
            *(floor1+q) = maxFloor1;
            *(floor2+q) = maxFloor2;
           q++;
        }
    }
     
     averunt = min(run_t1,171);
     avet = min(ave_t1,171);
     maxFloor1 = *(floor1+searchmin(run_t1,171));
     maxFloor2 = *(floor2+searchmin(run_t1,171));
     printf("\nSenario 4:\nThe recommended maxFloor1 is %d and maxFloor2 is %d. In this case,\n", maxFloor1, maxFloor2);
     printf("The minimum average time to complete the elevator run is %f\n", averunt);
     printf("The mimimum average waiting time for each passenger is %f\n", avet);


    free(run_t);
    free(ave_t);
    return(0);
}