//c program for fifo pagereplacement algorithm

#include<stdio.h>
int main(){
    int referenceString[10],pagefaults = 0,m,n,s,pages,frames;
    printf("\n Enter the number of pages : \t");
    scanf("%d",&pages);
    printf("\n Enter reference String values :\n");
    for( m = 0;m < pages; m++){
        printf("Value No. [%d]: \t",m+1);
        scanf("%d", &referenceString[m] );
    }
    
    printf("\n total number of frames :\t");
    {
          scanf("%d",&frames);
    }
    
    int temp[frames];
     for( m = 0;m < frames; m++){
         temp[m] = -1;
     }
     
     for( m = 0;m < pages; m++){
           s=0;
           for( n = 0;n < frames; n++){
              if(referenceString[m] == temp[n]){
                s++;
                pagefaults--;
               }
            }
            pagefaults++;
     if((pagefaults <= frames) && (s == 0))
        {
          temp[m] = referenceString[m];
        }
     else if(s == 0)
        {
          temp[(pagefaults -1) % frames] = referenceString[m];
        }
        
        printf("\n");
        
        for( n = 0;n < frames; n++)
        {
        printf("%d\t", temp[n]);
        }
        
    }
    
    printf("\n Total page faults : \t%d\n",pagefaults);
    return 0;
    }    
                  
