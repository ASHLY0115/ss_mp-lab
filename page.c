


#include<stdio.h>
int p,page[20],f,frame[10],hit=0,fault=0,count,i,j,next[20],flag[20],freq[20],choice,next1[20];
void input(){
 printf("Enter number of reference pages:");
 scanf("%d",&p);
 printf("Enter the requested pages:");
 for( i=0;i<p;i++)
 scanf("%d",&page[i]);
 printf("Enter the frame number:");
 scanf("%d",&f);
 for( i=0;i<f;i++){
    frame[i]=-1;
 }
}
void FIFO(){
  count=0;
  for( i=0;i<p;i++){
    for( j=0;j<f;j++){
        if(page[i]==frame[j]){
            hit++;
            break;
        }
    }
    if(j==f){
      frame[count]=page[i];
      count++;
      fault++;
    }
    printf("\n");
    for( j=0;j<f;j++)
      printf("%d\t",frame[j]);
    if(count==f){
      count=0;
    }
  }
  printf("\nPage fault:%d\nPage hit:%d",fault,hit);
}

void LRU(){
    count=0;
    for(i=0;i<p;i++){
        flag[i]=0;
        for(j=0;j<f;j++){
            if(page[i]==frame[j]){
                next[j]=count;
                count++;
                hit++;
                flag[i]=1;
            }
        }
        if(flag[i]==0){
          if(i<f){
          for(j=0;j<f;j++){
            if(frame[j]==-1){
                frame[j]=page[i];
                next[j]=count;
                count++;
                break;
            }
          }
          }
            else{
               int min=0;
               for(j=1;j<f;j++){
                if(next[min]>next[j]){
                    min=j;
                }
               }
               frame[min]=page[i];
               next[min]=count;
               count++;
            }
            flag[i]=1;
            fault++;
        }
    printf("\n");
    for( j=0;j<f;j++)
      printf("%d\t",frame[j]);
    }
    printf("\nPage fault:%d\nPage hit:%d",fault,hit);
}
void LFU(){
  count=0;
    for(i=0;i<p;i++){
        for(j=0;j<f;j++){
         if(page[i]==frame[j]){
            freq[j]++;
            hit++;
            break;
            }
        }
        if(j==f){
            int min=0;
            for(j=1;j<f;j++){
                if(freq[min]>freq[j]){
                min=j;
                 }

                else if(freq[min]==freq[j]){
                 if(next1[min]>next1[j]){
                  min=j;
                 }
                
                }
            }
            frame[min]=page[i];
            freq[min]=1;
            next1[min]=count;
            count++;  
            fault++;
           }
           printf("\n");
       for( j=0;j<f;j++)
       printf("%d\t",frame[j]);
        }
      printf("\nPage fault:%d\nPage hit:%d",fault,hit);
    }

int main(){
 do{
  fault=0;
  hit=0;
  printf("\n1.FIFO\n2.LRU\n3.LFU\n4.Exit\nSelect your choice:");
  scanf("%d",&choice);
  switch(choice){
    case 1:
    input();
    FIFO();
    break;
    case 2:
    input();
    LRU();
    break;
    case 3:
    input();
    LFU();
    break;
    case 4:
printf("EXIT\n");
    break;
    default:
    printf("Invalid choice\n");

  }
 }while(choice!=4);
}
