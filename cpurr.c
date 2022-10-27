#include<stdio.h>
int main(){
	int i,n,total=0,x,flag=0,timeQuantum;
	int wt=0,tt=0,at[10],bt[10],temp[10];
	float avgwt,avgtt;
	printf("Enter the total number of processes:");
	scanf("%d",&n);
	x=n;
	for(i=0;i<n;i++){
		printf("Enter the details of Process[%d]:\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst time:");
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	printf("Enter the time quantum:");
	scanf("%d",&timeQuantum);
	printf("\nProcess\tBurst Time\tTurnaound Time\tWaiting Time\n");
	for(total=0,i=0;x!=0;){
		if(temp[i]<=timeQuantum&&temp[i]>0){
			total+=temp[i];
			temp[i]=0;
			flag=1;
		}
		else if(temp[i]>0){
			temp[i]=temp[i]-timeQuantum;
			total=total+timeQuantum;
		}
		if(temp[i]==0 &&flag==1){
			x--;
			printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
			wt+=total-at[i]-bt[i];
			tt+=total-at[i];
			flag=0;
			}
		if(i==n-1){
			i=0;
		}
		else if(at[i+1]<=total){
			i++;
			}
		else{
			i=0;
		}
	}
	
	avgwt=wt*1.0/n;
	avgtt=tt*1.0/n;
	printf("\nAverage waiting time:%.2f",avgwt);
	printf("\nAverage Turnaround Time:%.2f",avgtt);
	return 0;
	}						



