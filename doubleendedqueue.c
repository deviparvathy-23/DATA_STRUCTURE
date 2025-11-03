#include <stdio.h>
int q[20],size,f=-1,r=-1;
void rear_enqueue();
void front_dequeue();
void front_enqueue();
void rear_dequeue();
void display();
void rear_enqueue()
{
    int iteam;
    if(f==0 && r==size-1|| f==r+1)
    {
        printf("Queue full at rear");
    }
    else
    {
         r+=1;
         printf("\nEnter iteam to be inserted-");
         scanf("%d",&iteam);
         q[r]=iteam;
         printf("\n---------------------------\n");
         printf("Inserted iteam=%d",iteam);
         printf("\n---------------------------\n");
         if(f==-1)
         {
            f=0;
         }
    }
    display();
}
void front_enqueue()
{
    int iteam;
    if(f==0 && r==size-1|| f==r+1)
    {
        printf("Queue full at front");
    }
    else 
    {
         if(f==-1)
         {
            f=r=0;
         }
         else if(f==0)
         {
            f=size-1;
         }
         else
         {
            f--;
         }
         printf("\nEnter iteam to be inserted-");
         scanf("%d",&iteam);
         q[f]=iteam;
         printf("\n---------------------------\n");
         printf("Inserted iteam=%d",iteam);
         printf("\n---------------------------\n");
         display();
    }
    
    
}
void front_dequeue()
{
    int iteam;
    if(f==-1)
    {
        printf("Queue empty");
    }
    else
    {
        iteam=q[f];
        f++;
        if(f>r)
        {
            f = r = -1;
        }
        printf("\ndeleted iteam=%d\n",iteam);
        display();


    }
}
void rear_dequeue()
{
    int iteam;
    if(r==-1)
    {
        printf("Queue empty");
    }
    else
    {
        iteam=q[r];
        r--;
        if(f>r)
        {
            f = r = -1;
        }
        printf("\ndeleted iteam=%d\n",iteam);
        display();


    }
}
void display()
{
    if(f==-1)
    {
        printf("\n");
        printf("\nQueue empty");
        printf("\n");
    }
    else
    {
        int i = f;
        for(i=f;i<=r;i++)
        {
            printf("%d",q[f]);
        }
    printf("\n");
    }
}
int main()
{
    int n;
    char ch='y';
    printf("ENTER SIZE==");
    scanf("%d",&size);
    while(ch=='y')
    {
    printf("\nMENU\n 1:INSERT ELEMENT THROUGH REAR\n 2:DELETE ELEMENT FROM REAR\n 3:INSERT ELEMENT THROUGH FRONT\n 4:DELETE ELEMENT FROM FRONT\n 5:DISPLAY QUEUE \n 6:Exit\n");
        printf("\nEnter choice-");
        scanf("%d",&n);
        switch(n)
        {
            case 1: rear_enqueue();
                    break;
            case 2:rear_dequeue();
                    break;
            case 3:front_enqueue();
                    break;
            case 4:front_dequeue();
                    break;
            case 5:display();
                    break;

            case 6:ch='n';
                    break;


            default:printf("Invalid choice\n");
        }
    }
    return 0;
}