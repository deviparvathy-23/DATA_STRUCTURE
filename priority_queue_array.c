#include <stdio.h> 
int pq[20][20],size,priority; 
int f[10],r[10]; 
int maxp; 
void enqueue(); 
void dequeue(); 
void display(); 
void enqueue() 
{ 
        int item; 
 printf("\nEnter the priority level-"); 
        scanf("%d",&priority); 
 if(priority>maxp || priority<1) 
 { 
  printf("Invalid priority\n"); 
 } 
        else if(r[priority-1]==size-1) 
        { 
                printf("Queue full at priority %d",priority); 
        } 
        else 
        { 
                r[priority-1]=r[priority-1]+1; 
                printf("\nEnter item to be inserted-"); 
                scanf("%d",&item); 
                pq[priority-1][r[priority-1]]=item; 
                printf("inserted item-%d",pq[priority-1][r[priority-1]]); 
                if(f[priority-1]==-1) 
                { 
                        f[priority-1]=0; 
                } 
  display(); 
        } 
 
} 
void dequeue() 
{ 
        int item; 
 int i=0; 
        while(i<maxp && f[i]==-1) 
 { 
                i++; 
        } 
 if(i==maxp) 
 { 
  printf("Queue empty\n"); 
 } 
        else 
        { 
                item=pq[i][f[i]]; 
                f[i]=f[i]+1; 
  printf("\ndeleted item=%d",item); 
                if(f[i]>r[i]) 
                { 
                        f[i]=r[i]=-1; 
                } 
  display(); 
        } 
  
} 
void display() 
{ 
 int i=0; 
 while(i<maxp && f[i]==-1) 
        { 
                i=i+1; 
        } 
        if(i==maxp) 
        { 
                printf("\nQueue empty\n"); 
        } 
        else 
        { 
                int i=0; 
  int j; 
  for(i=0;i<maxp;i++) 
  { 
   printf("\nPriority%d\t",i+1); 
   for(j=f[i];j<=r[i];j++) 
   { 
    printf("%d\t",pq[i][j]); 
   } 
  
   printf("\n"); 
  } 
 } 
} 
int main() 
{ 
        int item,n; 
 int i,j; 
 printf("Enter size of queue-"); 
        scanf("%d",&size); 
        printf("Enter maximum priority levels=\n"); 
        scanf("%d",&maxp); 
 for(i=0;i<maxp;i++) 
 { 
  f[i]=-1; 
  r[i]=-1; 
 } 
 
        char ch='y'; 
        printf("MENU\n 1:INSERT ELEMENT\n 2:DELETE ELEMENT\n 3:DISPLAY QUEUE\n 4:Exit\n"); 
        while(ch=='y') 
        { 
        printf("\nEnter choice-"); 
        scanf("%d",&n); 
        switch(n) 
        { 
                case 1: enqueue(); 
                        break; 
                case 2:dequeue(); 
                        break; 
                case 3:display(); 
                        break; 
                case 4:ch='n'; 
                        break; 
                default:printf("Invalid choice\n"); 
 
        } 
        } 
        return 0; 
}
