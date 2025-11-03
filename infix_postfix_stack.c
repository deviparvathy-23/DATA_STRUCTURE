#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 
char temp[50]; 
int top=-1; 
char post[20]; 
char pop(char st[]) 
{ 
    if (top == -1) { 
        return '\0';  
    } 
    char item=st[top]; 
    top--; 
    return item; 
} 
void push(char a,char st[]) 
{ 
    top++; 
    st[top]=a; 
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
    { 
        return 2; 
    } 
    else if(a=='*'||a=='/') 
    { 
        return 4; 
    } 
    else if(a=='^') 
    { 
       return 5; 
    } 
    else if(a=='(') 
    { 
       return 0; 
    } 
    else{ 
        return 0; 
    } 
} 
int evaluatePostfix(char postfix[]) { 
    int stack[50], tops = -1, i = 0; 
    char item; 
    while(postfix[i]!='\0') 
    { 
        item=postfix[i]; 
        if(isdigit(item)) 
        { 
            stack[++tops]=item-'0'; 
        } 
        else 
        { 
            int x=stack[tops--]; 
            int y=stack[tops--]; 
            int res; 
            switch(item) 
            { 
                case '+':res=y+x; 
                        break; 
                case '-':res=y-x; 
                        break; 
                case '*':res=y*x; 
                        break; 
                case '/':res=y/x; 
                        break; 
                case '^':res=pow(y,x); 
                        break; 
            } 
            stack[++tops]=res; 
        } 
        i++; 
    } 
    return stack[tops]; 
} 
int main() 
{ 
    char exp[20],item,x; 
    int i=0,k=0; 
    printf("Enter expression:"); 
    scanf("%s",exp); 
    strcat(exp,")"); 
    push('(',temp); 
    while(exp[i]!='\0') 
    { 
        item=exp[i]; 
        x=pop(temp); 
        if(isalnum(item)) 
        { 
            post[k++]=item; 
            push(x,temp); 
        } 
        else if(item==')') 
        { 
            while(x!='(') 
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
    printf("%s",post); 
    printf("\n"); 
    strcat(post,"#"); 
    printf("%d",evaluatePostfix(post)); 
     
}
