#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
char temp[50],post[40]; 
int top=-1; 
char* strrev(char* str) 
{ 
 char *start=str; 
 char *end=str+strlen(str)-1; 
 char temp; 
 while(end>start) 
 { 
  temp=*start; 
  *start=*end; 
  *end=temp; 
  start++; 
  end--; 
 } 
 return str; 
} 
char pop() 
{ 
    if (top == -1) { 
        return '\0';  
    } 
    char item=temp[top]; 
    top--; 
    return item; 
} 
void push(char a,char temp[]) 
{ 
    top++; 
    temp[top]=a; 
} 
int icp(char a) 
{ 
    if(a=='+'||a=='-') 
    { 
        return 1; 
    } 
    else if(a=='*'||a=='/') 
    { 
        return 3; 
    } 
    else if(a=='^') 
    { 
       return 6; 
    } 
    else if(a=='(') 
    { 
       return 7; 
    } 
    else{ 
        return 6; 
    } 
} 
int isp(char a) 
{ 
    if(a=='+'||a=='-') 
        return 2; 
    else if(a=='*'||a=='/') 
        return 4; 
    else if(a=='^') 
       return 5; 
    else if(a=='(') 
       return 0; 
    else 
        return 0; 
} 
int main() 
{ 
    char exp[20],item,x; 
    int i=0,k=0; 
    printf("Enter expression:"); 
    scanf("%s",exp); 
    strrev(exp); 
    strcat(exp,"(#"); 
    push(')',temp); 
    while(exp[i]!='#') 
    { 
        item=exp[i]; 
        x=pop(temp); 
        if(isalnum(item)) 
        { 
            post[k++]=item; 
            push(x,temp); 
        } 
        else if(item=='(') 
        { 
            while(x!=')') 
            { 
               post[k++]=x; 
               x=pop(temp); 
            } 
 
        } 
        else if(isp(x)>=icp(item)) 
        { 
            while(isp(x)>=icp(item)) 
            { 
               post[k++]=x; 
               x=pop(temp); 
            } 
            push(x,temp); 
            push(item,temp); 
        } 
        else if(isp(x)<icp(item)) 
        { 
            push(x,temp); 
            push(item,temp); 
        } 
        i++; 
    } 
    strrev(post); 
    printf("%s",post); 
    printf("\n"); 
    return 0; 
} 
