#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
 int n,i; 
 printf("Enter no of elements-"); 
 scanf("%d",&n); 
 int *ptr=(int *)malloc(n*(sizeof(int))); 
 int key; 
 printf("Enter elements to be inserted-"); 
 for(i=0;i<n;i++) 
 { 
  scanf("%d",&ptr[i]); 
 } 
 printf("Enter key to be searched-"); 
 scanf("%d",&key); 
 for(i=0;i<n;i++) 
        { 
                if(ptr[i]==key) 
  { 
   printf("Element found at position %d\n",i+1); 
   break; 
  } 
        } 
 if(i==n) 
 { 
  printf("Element not found\n"); 
 } 
 free(ptr); 
 
}
