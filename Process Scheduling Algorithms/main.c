#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Maximum number of processes
#define MAX_PROC 10


struct process{
    int pid;
    int arrival_time;
    int priority;
    int burst_time;
}
;
// Arrival time comparison function for qsort
int compByArrivalTime(const void *a, const void *b)
{
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;
    return p1->arrival_time - p2->arrival_time;
}

//Calculate and print the process information
void printInfos(struct process p[], int lineCount){
    double totalWaitingtime=0;
    double totalTurnaroundtime=0;
    int initialExecutiontime= 0;
    for(int i=0;i<lineCount;i++){
        totalWaitingtime+=initialExecutiontime-p[i].arrival_time;
        initialExecutiontime+=p[i].burst_time;
        totalTurnaroundtime+=initialExecutiontime-p[i].arrival_time;
        printf("Procesess %d  Completion Time: %d \n" ,p[i].pid, initialExecutiontime);
    }
        printf("Avarege Turnaround Time: %.2f\n" ,totalTurnaroundtime/lineCount);
        printf("Avarege Waiting Time: %.2f \n" ,totalWaitingtime/lineCount);

}
//First Come First Serve Algorithm
void FCFS(struct process p[],int lineCount)

{
    qsort(p, lineCount, sizeof(struct process), compByArrivalTime);
    printInfos(p,lineCount);
}
//Shortest Job First Algorithm
void SJF(struct process p[],int lineCount){
    qsort(p, lineCount, sizeof(struct process), compByArrivalTime);
    int initialExecutiontime= 0;
    for(int i=0;i<lineCount;i++){
        for (int j = 0 ;j+i<lineCount-1 ; j++){
        if((p[j].arrival_time == p[j+1].arrival_time&&p[j].burst_time>p[j+1].burst_time)
            ||(initialExecutiontime>=p[j+1].arrival_time&&p[j].burst_time>p[j+1].burst_time)){


                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                initialExecutiontime+=p[j].burst_time;

        }
        else{
            initialExecutiontime+=p[j].burst_time;

        }
    }
        initialExecutiontime=0;
    }

printInfos(p,lineCount);
}
//Priority Algorithm
void PRIO(struct process p[],int lineCount){
    qsort(p, lineCount, sizeof(struct process),compByArrivalTime);
    int initialExecutiontime= 0;
    for(int i=0;i<lineCount;i++){
        for (int j = 0 ;j+i<lineCount-1; j++){
        if((p[j].arrival_time == p[j+1].arrival_time&&p[j].priority>p[j+1].priority)
            ||(initialExecutiontime>=p[j+1].arrival_time&&p[j].priority>p[j+1].priority)){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                initialExecutiontime+=p[j].burst_time;

        }
        else{
            initialExecutiontime+=p[j].burst_time;

        }


}
        initialExecutiontime=0;
    }

    printInfos(p,lineCount);
}

int main(int argc, char *argv[]) {
    int lineCount =0;


   FILE *fp = fopen(argv[2], "r");
   char myString [32];
   struct process pArray[MAX_PROC];

;
// Create a process array from the input file
while(fgets(myString, sizeof(myString), fp) != NULL){

      struct process p;

      p.pid=myString[0]-'0';
      p.arrival_time=myString[2]-'0';
      p.priority=myString[4]-'0';
      p.burst_time=myString[6]-'0';
      pArray[lineCount++]=p;


  }
    fclose(fp);
// Choose the algorithm

  if (strcmp(argv[1], "FCFS") == 0){
      FCFS(pArray,lineCount);


  }
  else if (strcmp(argv[1], "SJF")== 0) {
        SJF(pArray,lineCount);

  }

  else if (strcmp(argv[1], "PRIO")== 0) {
        PRIO(pArray,lineCount);

  }
  else
  {
      printf("Invalid input");}

}
