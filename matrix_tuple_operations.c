#include <stdio.h> 
#include <stdlib.h> 
typedef struct matrix { 
int row; 
int col; 
int val; 
} matrix; 
matrix* tuple(int n, int m); 
void display(matrix* term); 
matrix* transpose(matrix* trans); 
matrix* sumofmatrix(matrix* term1, matrix* term2); 
int main() { 
int n1, m1, n2, m2, i, j, k; 
printf("Enter no of rows of matrix 1-"); 
scanf("%d", &n1); 
printf("Enter no of columns of matrix 1-"); 
scanf("%d", &m1); 
matrix* term1 = tuple(n1, m1); 
printf("Enter no of rows of matrix 2-"); 
scanf("%d", &n2); 
printf("Enter no of columns of matrix 2-"); 
scanf("%d", &m2); 
matrix* term2 = tuple(n2, m2); 
matrix* trans1 = transpose(term1); 
matrix* trans2 = transpose(term2); 
display(term1); 
printf("TRANSPOSE MATRIX\n"); 
display(trans1); 
display(term2); 
printf("TRANSPOSE MATRIX\n"); 
    display(trans2);  
    matrix* add=sumofmatrix(term1,term2); 
    if(add!=NULL) 
    { 
        printf("SUM MATRIX\n"); 
        display(add); 
    } 
} 
matrix* tuple(int n, int m) { 
    int k = 1, i = 0, j = 0; 
    int a; 
    matrix* term = (matrix*)malloc((m * n) * sizeof(matrix)); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) { 
            printf("Enter element %d %d: ", i, j); 
            scanf("%d", &a); 
            if (a != 0) { 
                term[k].row = i; 
                term[k].col = j; 
                term[k].val = a; 
                k++; 
            } 
        } 
    } 
    term[0].row = n; 
    term[0].col = m; 
    term[0].val = k - 1; 
    return term; 
} 
void display(matrix* term) 
{ 
    printf("row\tcolumn\tvalue\n"); 
    for(int i=0;i<=term[0].val;i++) 
    { 
        printf("%d\t%d\t%d\n",term[i].row,term[i].col,term[i].val); 
    } 
} 
matrix* transpose(matrix* term) 
{ 
    matrix* trans=(matrix*)malloc((term[0].val+1)*sizeof(matrix)); 
    int n=term[0].val; 
    int i=0,j=0; 
    trans[0].row=term[0].row; 
    trans[0].col=term[0].col; 
    trans[0].val=n; 
    if(n>0) 
    { 
        int q=1; 
        for(i=0;i<term[0].col;i++) 
        { 
            for(j=1;j<=n;j++) 
            { 
                if(term[j].col==i) 
                { 
                    trans[q].row=term[j].col; 
                    trans[q].col=term[j].row; 
                    trans[q].val=term[j].val; 
                    q++; 
                } 
            } 
        } 
    } 
    return trans; 
} 
matrix* sumofmatrix(matrix* term1, matrix* term2) 
{ 
    matrix* sum=(matrix*)malloc((term1[0].row*term1[0].col)*sizeof(matrix));  
    if(term1[0].row!= term2[0].row || term1[0].col!=term2[0].col) 
    { 
        printf("Addition not possible"); 
       return NULL; 
    } 
    else 
    { 
        int i=1,j=1,k=1; 
        while(i<term1[0].val+1&&j<term2[0].val+1) 
        { 
            if(term1[i].row<term2[j].row) 
            { 
                sum[k]=term1[i]; 
                k++; 
                i++; 
            } 
            else if(term1[i].row>term2[j].row) 
            { 
                sum[k]=term2[j]; 
                k++; 
                j++; 
            } 
            else 
            { 
                if(term1[i].col<term2[j].col) 
                { 
                    sum[k]=term1[i]; 
                    k++; 
                    i++; 
                } 
                else if(term1[i].col>term2[j].col) 
                { 
                    sum[k]=term2[j]; 
                    k++; 
                    j++; 
                } 
                else 
                { 
                    sum[k].row=term2[j].row; 
                    sum[k].col=term2[j].col; 
                    sum[k].val=term1[i].val+term2[j].val; 
                    k++; 
                    j++; 
                    i++; 
                } 
            } 
        } 
        while(i<term1[0].val+1) 
        { 
            sum[k]=term1[i]; 
            k++; 
            i++; 
        } 
        while(j<term2[0].val+1) 
        { 
            sum[k]=term2[j]; 
            k++; 
            j++; 
        } 
        sum[0].row=term1[0].row; 
        sum[0].col=term1[0].col; 
sum[0].val=k-1; 
} 
return sum; 
}
