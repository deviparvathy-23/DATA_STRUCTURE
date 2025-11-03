#include <stdio.h> 
#include<string.h> 
char stack[50]; 
char rev[50]; 
int top1=-1,top2=-1; 
char pop(char stack[], int *top) 
{ 
    if (*top == -1) 
    { 
        return '\0'; 
    } 
    else 
    { 
        char item = stack[*top]; 
        (*top)--; 
        return item; 
    } 
} 
void push(char a, char stack[], int *top) 
{ 
    (*top)++; 
    stack[*top] = a; 
} 
 
void main() 
{ 
    char str[10],x; 
    int i; 
    printf("Enter string-"); 
    scanf("%s",str); 
    int l=strlen(str); 
    for(int i=0;str[i]!='\0';i++) 
    { 
        push(str[i],stack,&top1); 
 
    } 
    x = pop(stack, &top1); 
    while(x!='\0') 
    { 
       push(x,rev,&top2); 
         x = pop(stack, &top1); 
    } 
    for (i = 0; i < l; i++) 
    { 
        if (str[i] != rev[i]) 
        { 
            printf("Not a palindrome\n"); 
            break; 
        } 
    } 
    if(i==l) 
     printf("Is a palindrome\n"); 
} 
