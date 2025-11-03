#include <stdio.h> 
int stack[50]; 
int size; 
int top=-1; 
void pop() 
{ 
    if (top == -1) { 
        printf("Stack underflow\n"); 
    } 
    else{ 
    int item=stack[top]; 
    top--; 
    printf("Deleted element-%d\n",item); 
    } 
} 
void push() 
{ 
    int a; 
    if(top==size-1) 
    { 
        printf("Stack Overflow\n"); 
    } 
    else{ 
    top++; 
    printf("Enter element to be inserted:"); 
    scanf("%d",&a); 
    stack[top]=a; 
    } 
} 
void main() 
{ 
    int n; 
    char ch='y'; 
    printf("Enter size of stack:"); 
    scanf("%d",&size); 
    printf("MENU\n 1:PUSH ITEM\n 2:POP ITEM\n 3:BREAK\n"); 
    while(ch=='y') 
    { 
        printf("Enter choice-"); 
        scanf("%d",&n); 
        switch(n) 
        { 
           case 1:push(); 
                 break; 
            case 2:pop(); 
                    break; 
            case 3:ch='n'; 
                    break; 
        } 
    } 
} 
