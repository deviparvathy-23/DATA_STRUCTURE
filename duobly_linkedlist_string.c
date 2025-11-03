#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node 
{ 
    char data; 
    struct Node* rlink; 
    struct Node* llink; 
}Node; 
void Insert(Node* head,char x); 
void CheckPallindrome(Node* head); 
void Insert(Node* head,char x) 
{ 
    Node* ptr; 
    ptr=head; 
    while(ptr->rlink!=NULL) 
    { 
        ptr=ptr->rlink; 
    } 
    Node* new=(Node*)malloc(sizeof(Node)); 
    new->data=x; 
    new->llink=ptr; 
    new->rlink=NULL; 
    ptr->rlink=new; 
} 
void CheckPallindrome(Node* head) 
{ 
    Node* ptr=head->rlink; 
    Node* temp=head; 
    while(temp->rlink!=NULL) 
    { 
        temp=temp->rlink; 
    } 
    while(ptr<=temp) 
    { 
        if(ptr->data!=temp->data) 
        { 
            printf("Not pallindrome"); 
            break; 
        } 
        else{ 
            ptr=ptr->rlink; 
            temp=temp->llink; 
        } 
    } 
    if(ptr>temp) 
    { 
        printf("Pallindrome"); 
    } 
} 
int main() 
{ 
    char str[10]; 
    printf("Enter string-"); 
    scanf("%s",str); 
    int i=0; 
    Node* head; 
    head=(Node*)malloc(sizeof(Node)); 
    head->llink=NULL; 
    while(str[i]!='\0') 
    { 
        Insert(head,str[i]); 
        i++; 
    } 
Node* ptr = head->rlink; 
while (ptr != NULL) { 
printf("%c", ptr->data); 
ptr=ptr->rlink; 
} 
printf("\n"); 
CheckPallindrome(head); 
return 0; 
} 
