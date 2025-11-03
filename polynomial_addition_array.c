#include<stdio.h> 
struct poly 
{ 
 int exp; 
 int coeff; 
}p[10],q[10],r[10]; 
int main() 
{ 
 int n,m,i=0,j=0; 
 printf("Enter no of terms for p:"); 
 scanf("%d",&n); 
 while(i<n) 
 { 
  printf("Enter power of term %d:",i+1); 
  scanf("%d",&p[i].exp); 
  printf("Enter coefficient of term %d:",i+1); 
  scanf("%d",&p[i].coeff); 
  i++; 
 } 
 printf("\n"); 
  printf("Enter no of terms for q:"); 
        scanf("%d",&m); 
        while(j<m) 
        { 
                printf("Enter power of term %d:",j+1); 
                scanf("%d",&q[j].exp); 
                printf("Enter coefficient of term %d:",j+1); 
                scanf("%d",&q[j].coeff); 
  j++; 
        } 
 i=0; 
 while(i<m-1)         
 { 
  printf("%dx^%d+\t",p[i].coeff,p[i].exp); 
  i++; 
        } 
 printf("%dx^%d",p[i].coeff,p[i].exp); 
 printf("\n"); 
 i=0; 
 while(i<n-1) 
        { 
  printf("%dx^%d+\t",q[i].coeff,q[i].exp); 
  i++; 
        } 
 printf("%dx^%d",q[i].coeff,q[i].exp); 
 printf("\n"); 
 i=0; 
 j=0; 
 int k=0; 
 int sum; 
 while(i<n && j<m) 
 { 
  if(p[i].exp==q[j].exp) 
  { 
    sum=p[i].coeff+q[j].coeff; 
   if(sum!=0) 
   { 
    r[k].coeff=sum; 
    r[k].exp=p[i].exp; 
    i++,j++; 
    k++; 
   } 
   else 
   { 
    k++,i++,j++; 
   } 
  } 
  else if(p[i].exp>q[j].exp) 
  { 
   r[k].exp=p[i].exp; 
   r[k].coeff=p[i].coeff; 
   i++; 
   k++; 
 
  } 
  else 
  { 
   r[k].exp=q[j].exp; 
                        r[k].coeff=q[j].coeff; 
                        j++; 
   k++; 
 
  } 
 } 
 while(i<n) 
 { 
  r[k].exp=p[i].exp; 
                r[k].coeff=p[i].coeff; 
                i++; 
     k++; 
 
 } 
 while(j<m) 
 { 
  r[k].exp=q[j].exp; 
r[k].coeff=q[j].coeff; 
j++; 
} 
k++; 
printf("Result:\t"); 
i=0; 
while(i<k-1) 
{ 
} 
printf("%dx^%d+\t",r[i].coeff,r[i].exp); 
i++; 
printf("%dx^%d",r[i].coeff,r[i].exp); 
printf("\n"); 
return 0; 
} 
