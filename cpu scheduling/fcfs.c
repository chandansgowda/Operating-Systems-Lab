#include <stdio.h>

struct process {
	int pid;
	int at; //arrival time 
	int wt; //waiting time
	int bt; //burst time
	int ct; //completion time
	int tt; //turnaround time
};

int n; //number of processes
struct process p[50]; //list of process structures

void main(){
	int i,j;
	float tot_tt,tot_wt;
		
	printf("No. of process >> ");
	scanf("%d",&n);
	
	//getting input
	for(i=0; i<n;i++){
		printf("Process%d:\n", i+1);
		printf("Arrival Time: ");
		scanf("%d",&p[i].at);
		printf("Burst Time: ");
		scanf("%d",&p[i].bt);
		p[i].tt = p[i].wt = p[i].wt = 0; //initializing with 0
		p[i].pid = i+1; 
	}
	
	//sorting based on arrival time
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if (p[j].at > p[j+1].at){ //soryin based on arrival time
				struct process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	//calculating completion time
	int ct = p[0].at + p[0].bt;
	p[0].ct = ct;
	for(i=1;i<n;i++){
		ct += p[i].bt;
		p[i].ct = ct;
	}
	
	//calculating turnaround time and waiting time
	for(i=0;i<n;i++){
	
		//turnaround time
		p[i].tt = p[i].ct - p[i].at;
		tot_tt += p[i].tt;
		
		//waiting time
		p[i].wt = p[i].tt - p[i].bt;
		tot_wt += p[i].wt;
	}
	
	
	//printing output
	printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
	for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    printf("Avg waiting time = %.2f\nAvg turnaround time = %.2f\n", tot_wt / n, tot_tt / n);
	
	
}
