#include <stdio.h> 
int front=-1,rear=-1,q[20],size; 
void enqueue(); 
void dequeue(); 
void display(); 
void enqueue() 
{ 
 int item; 
 if(rear==size-1) 
 { 
  printf("Queue full"); 
 } 
 else 
 { 
  rear=rear+1; 
  printf("Enter iteam to be inserted-"); 
                scanf("%d",&item); 
  q[rear]=item; 
  printf("inserted item-%d",q[rear]); 
  if(front=-1) 
  { 
   front=0; 
  } 
 } 
 
} 
void dequeue() 
{ 
 int item; 
 if(front==-1) 
  printf("Queue empty"); 
 else; 
 { 
  item=q[front]; 
  front=front+1; 
  if(front>rear) 
  { 
   front=rear=-1; 
  } 
  printf("\ndeleted iteam=%d",item); 
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
  for(i=front;i<rear+1;i++) 
  { 
   printf("%d\t",q[i]); 
  } 
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
