#include <stdio.h> 
int front=-1,rear=-1,cq[20],size; 
void enqueue(); 
int dequeue(); 
void display(); 
void enqueue() 
{ 
        int item; 
        if(front==(rear+1)%size) 
        { 
                printf("Queue full"); 
        } 
        else 
        { 
                rear=(rear+1)%size; 
                printf("Enter item to be inserted-"); 
                scanf("%d",&item); 
                cq[rear]=item; 
                printf("inserted item-%d",cq[rear]); 
                if(front==-1) 
                { 
                        front=0; 
                } 
        } 
 display(); 
 
} 
int dequeue() 
{ 
        int item; 
        if(front==-1) 
        { 
                printf("Queue empty"); 
 
        } 
        else; 
        { 
                item=cq[front]; 
                front=(front+1)%size; 
                if(front==(rear+1)%size) 
                { 
                        front=rear=-1; 
                } 
                printf("\ndeleted item=%d",item); 
 
        } 
 
} 
void display() 
{ 
        int i; 
        if(front==-1) 
        { 
                printf("Queue empty"); 
        } 
        else 
        { 
  printf("\n------------------------------"); 
  printf("\nfront=%d\t rear=%d",front,rear); 
  printf("\n-------------------------------\n"); 
  i=front; 
  while(i!=rear) 
  { 
   printf("%d\t",cq[i]); 
   i=(i+1)%size; 
  } 
  printf("%d",cq[rear]); 
  printf("\n-------------------------------"); 
        } 
 
} 
int main() 
{ 
        int item,n; 
        char ch='y'; 
        printf("Enter size of queue-"); 
        scanf("%d",&size); 
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
