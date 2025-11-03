#include <stdio.h> 
int main() 
{ 
    int n,i,mid,arr[10],key; 
    int start=0; 
    printf("Enter no of elements-"); 
    scanf("%d",&n); 
    int end=n; 
    printf("Enter inputs-"); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&arr[i]); 
    } 
    printf("Enter key to be searched-"); 
    scanf("%d",&key); 
    while(start<=end) 
    { 
 mid=(start+end)/2; 
        if(arr[mid]==key) 
        { 
        printf("found at %d",mid+1); 
        break; 
        } 
        else if(arr[mid]<key) 
        { 
           start=mid+1; 
        } 
        else if(arr[mid]>key) 
        { 
            end=mid-1; 
        } 
} 
if(start>end) 
{ 
  printf("Element not found");
} 
} 
