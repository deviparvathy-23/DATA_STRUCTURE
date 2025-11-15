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
void Sort(poly* head); 
void Add(poly* head1,poly* head2); 
void multiply(poly* head1,poly* head2); 
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
void multiply(poly* head1,poly* head2) 
{ 
 poly* pptr=head1->link; 
        poly* qptr; 
     poly * Rhead=(poly*)malloc(sizeof(poly)); 
     Rhead->link=NULL; 
     poly* rptr=Rhead; 
     while(pptr!=NULL) 
 { 
   qptr=head2->link; 
  while(qptr!=NULL) 
  { 
   poly* new= (poly*)malloc(sizeof(poly)); 
                 new->link=NULL; 
   new->coeff=pptr->coeff* qptr->coeff; 
   new->exp=pptr->exp+qptr->exp; 
   rptr->link=new; 
   rptr=new; 
   qptr=qptr->link; 
  } 
  pptr=pptr->link; 
 } 
 Sort(Rhead); 
} 
 
 
void Sort(struct poly* head) { 
    struct poly *ptr1, *ptr2, *prev; 
    ptr1 = head; 
    while (ptr1 != NULL) { 
        ptr2 = ptr1->link; 
        prev = ptr1; 
        while (ptr2 != NULL) { 
            if (ptr1->exp == ptr2->exp) { 
                ptr1->coeff += ptr2->coeff; 
                prev->link = ptr2->link; 
                free(ptr2); 
                ptr2 = prev->link;  
            } else { 
                prev = ptr2; 
                ptr2 = ptr2->link; 
            } 
        } 
        ptr1 = ptr1->link; 
    } 
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->link) { 
        for (ptr2 = ptr1->link; ptr2 != NULL; ptr2 = ptr2->link) { 
            if (ptr1->exp < ptr2->exp) { 
                int tempCoeff = ptr1->coeff; 
                int tempExp = ptr1->exp; 
                ptr1->coeff = ptr2->coeff; 
                ptr1->exp = ptr2->exp; 
                ptr2->coeff = tempCoeff; 
                ptr2->exp = tempExp; 
            } 
        } 
    } 
    Display(head);   
} 
int main() 
{ 
    int power=1,coeff=1; 
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
    multiply(Phead,Qhead); 
}
