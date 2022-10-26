#include<stdio.h>
int main(){
int i;
int at[10],bt[10],wt[10],ct[10],tat[10],pid[10],n;
printf("Enter the number of processes");
scanf("%d",&n);

for(i=0;i<n;i++)
{

printf("Enter the arrival time and burst time of p%d: ",i);
printf("\nArrival time :");
scanf("%d",&at[i]);
printf("Burst time:");
scanf("%d",&bt[i]);

}


ct[0]=bt[0]+at[0];
for(i=1;i<n;i++){
if(at[i]<ct[i-1]){
ct[i]=ct[i-1]+bt[i];
}
else
ct[i]=at[i]+bt[i];
}


for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
}


for(i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
}


printf("at    bt    ct    tat    wt");
printf("\n");
for(i=0;i<n;i++)
{
printf("%d    %d    %d    %d    %d",at[i],bt[i],ct[i],tat[i],wt[i]);
printf("\n");
}
int ttat=0,twt=0;
float avtat,avwt;
for(i=0;i<n;i++){
ttat+=tat[i];
twt+=wt[i];
avtat=ttat/n;
avwt=twt/n;
}
printf("The average turnaround time : %f",avtat);
printf("\n");
printf("The average waiting time :%f",avwt);
}
				
