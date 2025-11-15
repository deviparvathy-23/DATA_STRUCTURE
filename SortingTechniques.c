#include<stdio.h> 
#include<stdlib.h> 
int n,choice,key,size,low,high; 
int *arr; 
void bubblesort(int a[],int n); 
void insertionsort(int a[],int n); 
void selectionsort(int a[],int n); 
int minpos(int a[],int i,int m); 
void mergesort(int a[],int low,int high); 
void merge(int a[],int l,int m,int h); 
void quicksort(int a[],int low,int high); 
void heapsort(int a[],int n); 
void heapify(int a[],int n,int i); 
int main() 
{ 
    int i,*copy; 
    printf("Enter the number of terms of array:"); 
    scanf("%d",&size); 
    arr=(int*)malloc(size*sizeof(int)); 
    for(i=0;i<size;i++) 
    { 
        printf("Enter the element %d:",i+1); 
        scanf("%d",&arr[i]); 
    } 
    printf("Displaying the menu:\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Merge 
Sort\n5.Quick Sort\n6.Heap Sort\n7.Exit\n"); 
    while(1) 
    { 
         
        printf("Enter your choice:"); 
        scanf("%d",&choice); 
        copy=(int*)malloc(size*sizeof(int)); 
        for(i=0;i<size;i++) 
        { 
            copy[i]=arr[i]; 
        } 
        switch(choice) 
        { 
            case 1: 
            { 
                printf("The array enetered is:\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                bubblesort(copy,size); 
                printf("The sorted array using bubblesort\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                break; 
            } 
            case 2: 
            { 
                printf("The array enetered is:\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                insertionsort(copy,size); 
                printf("The sorted array using insertionsort\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                break; 
            } 
            case 3: 
            { 
                printf("The array enetered is:\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                selectionsort(copy,size); 
                printf("The sorted array using selectionsort\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                break; 
            } 
            case 4: 
            { 
                printf("The array enetered is:\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                low=0; 
                high=size-1; 
                mergesort(copy,low,high); 
                printf("The sorted array using mergesort\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                break; 
            } 
            case 5: 
            { 
                printf("The array enetered is:\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                quicksort(copy,0,size-1); 
                printf("The sorted array using quicksort\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                break; 
            } 
            case 6: 
            { 
                printf("The array enetered is:\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                heapsort(copy,size); 
                printf("The sorted array using heapsort\n"); 
                for(i=0;i<size;i++) 
                { 
                    printf("%d\t",copy[i]); 
                } 
                printf("\n"); 
                break; 
            } 
            case 7: 
            { 
                exit(0); 
                break; 
            } 
            default: 
            { 
                printf("Invalid choice\n"); 
                break; 
            } 
        } 
        free(copy); 
    } 
} 
void bubblesort(int a[],int n) 
{ 
    int i,j; 
    for(i=0;i<n-1;i++) 
    { 
        for(j=0;j<n-i-1;j++) 
        { 
            if(a[j]>a[j+1]) 
            { 
                int temp=a[j]; 
                a[j]=a[j+1]; 
                a[j+1]=temp; 
            } 
        } 
    } 
} 
void insertionsort(int a[],int n) 
{ 
    int i,j; 
    for(i=1;i<n;i++) 
    { 
        key=a[i]; 
        j=i-1; 
        while(j>=0&&a[j]>key) 
        { 
            a[j+1]=a[j]; 
            j--; 
        } 
        a[j+1]=key; 
    } 
} 
int minpos(int a[],int i,int m) 
{ 
    int j; 
    int least=i; 
    for(j=i+1;j<m;j++) 
    { 
        if(a[j]<a[least]) 
        { 
            least=j; 
        } 
    } 
    return least; 
} 
void selectionsort(int a[],int n) 
{ 
    int i; 
    for(i=0;i<n-1;i++) 
    { 
        int min=minpos(a,i,n); 
        int temp=a[i]; 
        a[i]=a[min]; 
        a[min]=temp; 
    } 
     
} 
void merge(int a[],int l,int m,int h) 
{ 
    int i=l; 
    int j=m+1; 
    int k=0; 
    int temp[size]; 
    while(i<=m&&j<=h) 
    { 
        if(a[i]<a[j]) 
        { 
            temp[k++]=a[i++]; 
        } 
        else if(a[j]<a[i]) 
        { 
            temp[k++]=a[j++]; 
        } 
    } 
    while(i<=m) 
    { 
        temp[k++]=a[i++]; 
    } 
    while(j<=h) 
    { 
        temp[k++]=a[j++]; 
    } 
    for (i=l,k=0;i<=h;i++,k++)  
    { 
        a[i]=temp[k]; 
    } 
} 
void mergesort(int a[],int low,int high) 
{ 
    if(low<high) 
    { 
        int mid=(low+high)/2; 
        mergesort(a,low,mid); 
        mergesort(a,mid+1,high); 
        merge(a,low,mid,high); 
    } 
} 
void quicksort(int a[],int low,int high) 
{ 
    if(low<high) 
    { 
        int i=low; 
        int j=high+1; 
        int pivot=a[low]; 
        while(i<j) 
        { 
            while(i<high&&a[i]<=pivot) 
            { 
                i++; 
            } 
            while(j>low&&a[j]>pivot) 
            { 
                j--; 
            } 
            if(i<j) 
            { 
                int temp=a[i]; 
                a[i]=a[j]; 
                a[j]=temp; 
            } 
        } 
        a[low]=a[j]; 
        a[j]=pivot; 
        quicksort(a,low,j-1); 
        quicksort(a,j+1,high); 
    } 
} 
void heapify(int a[],int n,int i)  
{ 
    int largest = i; 
    int left=2*i+1; 
    int right=2*i+2; 
    if (left<n&&a[left]>a[largest]) 
    { 
        largest=left; 
    } 
    if (right<n&&a[right]>a[largest])  
        largest=right; 
    if (largest!=i)  
    { 
        int temp=a[i]; 
        a[i]=a[largest]; 
        a[largest]=temp; 
        heapify(a,n,largest); 
    } 
} 
void heapsort(int a[],int n) 
{ 
    for (int i=(n/2)-1;i>=0;i--) 
        heapify(a, n, i); 
    for (int i=n-1;i>=0;i--) 
    { 
        int temp=a[0]; 
        a[0]=a[i]; 
        a[i]=temp; 
        heapify(a,i,0); 
    } 
} 
