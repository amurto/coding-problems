#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5 
struct queue
{
    int a[5];
    int front,rear;
};
init_queue(struct queue *p)
{
p->front=-1;
p->rear=-1;
}
void insertRear(struct queue *p,int val)
{
    if(p->front==0&&p->rear==MAX_SIZE-1)
    {
        printf("\nOverflow");
    }
    else if(p->front==p->rear==-1)
    {
        p->front=p->rear=0;
        p->a[p->front]=val;
    }
    else if(p->rear=MAX_SIZE-1)
    {
        p->rear=0;
        p->a[p->rear]=val;
    }
    else
    {
        p->rear++;
        p->a[p->rear]=val;
    }
}
void display(struct queue*p)
{
    printf("\n%d %d",p->front,p->rear);
    int i;
    if(p->front!=-1&&p->rear!=-1)
    {   
        i=p->front;
	    while(i!=p->rear)
		{
		printf("%d",p->a[i]);
		i=(i+1)%MAX_SIZE;
		}
		printf("%d \n",p->a[p->rear]);
    }
    else
    {
      printf("\n Queue Underflow");
    }
}
int main()
{
    char ch;
	int tmp;
	struct queue queue;
    init_queue(&queue);
	while(1)
	{
		printf("\n1. Enter from Front");
		printf("\n2. Enter from Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
		printf("\n5. Display");
		printf("\n6. Exit\n");
        scanf(" %c",&ch); 
	    /*if(ch =='1')
		{
			printf("\nAdd Data\t:");
			scanf("%d",&tmp);
			insertFront(&queue, tmp);
		}*/
        if(ch =='2')
		{
			printf("\nAdd Data\t:");
			scanf("%d",&tmp);
			insertRear(&queue, tmp);
		}/*		
		if(ch =='3')
		{
			tmp = deleteFront(&queue);
			printf("\nData Deleted: %d",tmp);
		}
        if(ch =='4')
		{
			tmp = deleteRear(&queue);
			printf("\nData Deleted: %d",tmp);
		}*/
		if(ch=='5')
		{
			printf("\nData in Queue is\t:");	
			display(&queue);
		}
		if(ch =='6')
			return 0;
	}
	return 0;
}

           
