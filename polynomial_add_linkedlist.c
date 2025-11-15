#include <stdio.h> 
#include <stdlib.h> 
typedef struct poly 
{ 
    int coeff; 
    int exp; 
    struct poly*link; 
}poly; 
void Insert(poly* head,int coeff,int power); 
void Display(poly* head); 
void Add(poly* head1,poly* head2); 
void Insert(poly* head,int coeff,int power) 
{ 
    poly* new= (poly*)malloc(sizeof(poly)); 
    new->coeff=coeff; 
    new->exp=power; 
    new->link=NULL; 
    if(head->link==NULL) 
    { 
        head->link=new; 
    } 
    else 
    { 
        poly* ptr=head->link; 
        while(ptr->link!=NULL) 
        { 
            ptr=ptr->link; 
        } 
        ptr->link=new; 
    } 
 
} 
void Display(poly* head) 
{ 
    if(head->link==NULL) 
    { 
        printf("Empty\n"); 
    } 
    else 
    { 
        poly* ptr=head->link; 
        while(ptr->link!=NULL) 
        { 
            printf("%dx^%d +",ptr->coeff,ptr->exp); 
            ptr=ptr->link; 
        } 
        printf("%dx^%d\n",ptr->coeff,ptr->exp); 
    } 
} 
void Add(poly* head1,poly* head2) 
{ 
    poly* pptr=head1->link; 
    poly* qptr=head2->link; 
    poly * Rhead=(poly*)malloc(sizeof(poly)); 
    Rhead->link=NULL; 
    poly* rptr=Rhead; 
    while(pptr!=NULL && qptr!=NULL) 
    { 
        poly* new= (poly*)malloc(sizeof(poly)); 
        new->link=NULL; 
 rptr->link=new; 
        rptr=new; 
 
        if(pptr->exp==qptr->exp) 
        {  
            new->coeff=pptr->coeff+qptr->coeff; 
            new->exp=pptr->exp; 
            pptr=pptr->link; 
            qptr=qptr->link; 
        } 
        else if(pptr->exp > qptr->exp) 
        { 
            rptr->coeff=pptr->coeff; 
            rptr->exp=pptr->exp; 
            pptr=pptr->link; 
        } 
        else 
        { 
            rptr->coeff=qptr->coeff; 
            rptr->exp=qptr->exp; 
            qptr=qptr->link; 
        } 
    } 
    while(pptr!=NULL) 
    { 
        poly* new= (poly*)malloc(sizeof(poly)); 
        new->coeff=pptr->coeff; 
        new->exp=pptr->exp; 
        new->link=NULL; 
        rptr->link=new; 
        rptr=new; 
        pptr=pptr->link; 
    } 
    while(qptr!=NULL) 
    { 
       poly* new= (poly*)malloc(sizeof(poly)); 
       new->coeff=qptr->coeff; 
       new->exp=qptr->exp; 
       new->link=NULL; 
       rptr->link=new; 
       rptr=new; 
       qptr=qptr->link; 
    } 
    Display(Rhead); 
} 
int main() 
{ 
    int power,coeff; 
    poly * Phead=(poly*)malloc(sizeof(poly)); 
    Phead->link=NULL; 
    printf("Enter terms of 1st polynomial\n"); 
    char ch='y'; 
    while(ch=='y') 
    { 
        printf("Enter coefficient of term:\n"); 
        scanf("%d",&coeff); 
        printf("Enter power of term:\n"); 
        scanf("%d",&power); 
        Insert(Phead,coeff,power); 
        printf("Do you want to add more(y/n)-\n"); 
        scanf(" %c",&ch); 
    } 
    printf("Enter terms of 2nd polynomial\n"); 
    poly * Qhead=(poly*)malloc(sizeof(poly)); 
    Qhead->link=NULL; 
    ch='y'; 
    while(ch=='y') 
    { 
        printf("Enter coefficient of term:\n"); 
scanf("%d",&coeff); 
printf("Enter power of term:\n"); 
scanf("%d",&power); 
Insert(Qhead,coeff,power); 
printf("Do you want to add more(y/n)-\n"); 
scanf(" %c",&ch); 
} 
Display(Phead); 
Display(Qhead); 
Add(Phead,Qhead); 
} 
