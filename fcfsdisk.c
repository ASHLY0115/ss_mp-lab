#include<stdio.h>
int main(){
    int i,n,diskSize,intialP,request[20],point,TotalHeadM=0;
    printf("Enter no of requests :- ");
    scanf("%d",&n);
    printf("Enter the request sequence :- \n");
    for(i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("Enter intial position of head :- ");
    scanf("%d",&intialP);
    point=intialP;
    for(i=0;i<n;i++){
        if(point<request[i]){
            TotalHeadM+=(request[i]-point);
            point=request[i];
        }
        else{
            TotalHeadM+=(point-request[i]);
            point=request[i];
        }
    }
    printf("Total Head movement :- %d",TotalHeadM);
    return 0;
}
