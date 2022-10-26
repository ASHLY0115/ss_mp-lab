#include<stdio.h>
int main()
{
int wt[10],bt[10],tat[10],p[10];
int i,j,n,pos,temp,total;
float avg_wt,avg_tat;
printf("Enter the number of process : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the burst time of p%d: ",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
{
 pos=j;
 temp=bt[i];
 bt[i]=bt[pos];
 bt[pos]=temp;

 temp=p[i];
 p[i]=p[pos];
 p[pos]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
{
wt[i]+=bt[j];
}
total+=wt[i];
}
avg_wt=(float)total/n;
total=0;
printf("\nProcess\t Burst time  \tWaiting time  Turnaround time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\np%d\t\t%d\t\t %d\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
avg_tat=(float)total/n;
printf("\nThe average waiting time :%f",avg_wt);
printf("\nThe average turnaround time :%f",avg_tat);

}








