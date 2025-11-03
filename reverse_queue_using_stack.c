#include <stdio.h> 
#include<stdlib.h> 
typedef struct Node 
{ 
    int data; 
    struct Node* link; 
}Node; 
Node* front=NULL; 
Node* rear=NULL; 
void Push(Node*head,int item); 
int Pop(Node*head); 
void display(Node*head); 
void Enqueue(Node*head,int item); 
void Display(Node*head); 
void Reverse(Node* head); 
int Dequeue(Node*head); 
void Display(Node* head) 
{ 
    if(front==NULL) 
    { 
         printf("Queue empty\n"); 
         return; 
    } 
    else 
    { 
        Node*ptr=front; 
        while(ptr!=NULL) 
        { 
            printf("%d\t",ptr->data); 
            ptr=ptr->link; 
        } 
        printf("\n"); 
    } 
} 
void Push(Node*head,int item) 
{ 
    Node* top=head->link; 
    Node* newnode=(Node*)malloc(sizeof(Node)); 
    newnode->data=item; 
    newnode->link=head->link; 
    top=newnode; 
    head->link=top; 
} 
int Pop(Node*head) 
{ 
     Node* top=head->link; 
     int temp; 
     if(top==NULL) 
     { 
        printf("Stack empty\n"); 
     } 
     else 
     { 
        Node* ptr=top->link; 
        temp=top->data; 
        head->link=ptr; 
        free(top); 
        top=ptr; 
        return temp; 
     } 
} 
void display(Node*head) 
{ 
    Node* top=head->link; 
     if(top==NULL) 
    { 
        printf("Stack empty\n"); 
    } 
    else{ 
         while(top!=NULL) 
         { 
             printf("%d\t",top->data); 
             top=top->link; 
         } 
         printf("\n"); 
    }   
 
} 
void Enqueue(Node* head,int item) 
{ 
    Node* newnode=(Node*)malloc(sizeof(Node)); 
    newnode->data=item; 
    newnode->link=NULL; 
    if(rear==NULL) 
    { 
        rear=front=newnode; 
        head->link=rear; 
    } 
    else 
    { 
        rear->link=newnode; 
        rear=newnode; 
    } 
} 
int Dequeue(Node*head) 
{ 
    int x; 
    if(front==NULL) 
    { 
       printf("Queue empty\n"); 
    } 
    else 
    { 
       Node*temp=front; 
        x=temp->data; 
        front=temp->link; 
        free(temp); 
        if(front==NULL) 
        { 
            rear=NULL; 
        } 
         return x; 
    } 
     
} 
void Reverse(Node* head) 
{ 
    Node* head2=(Node*)malloc(sizeof(Node)); 
    head2->link=NULL; 
    while(front!=NULL) 
    { 
        Push(head2,Dequeue(head)); 
    } 
    while(head2->link!=NULL) 
    { 
        Enqueue(head,Pop(head2)); 
    } 
free(head2); 
} 
int main() 
{ 
Node* head1=(Node*)malloc(sizeof(Node)); 
char ch='y'; 
int item; 
head1->link=NULL; 
while(ch=='y') 
{ 
printf("Enter elements of the Queue-"); 
scanf("%d",&item); 
Enqueue(head1,item); 
printf("Do you want to add more elment-"); 
scanf(" %c",&ch); 
Display(head1); 
Reverse(head1); 
Display(head1);
}
}
