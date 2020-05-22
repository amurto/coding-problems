#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct queue
{
	int front;
	int rear;
	int a[SIZE];
}*q;

void init_queue(struct queue *q)
{
	q->front=-1;
	q->rear=-1;
}

void enque(struct queue *q, int x)
{
	if((q->front==0 && q->rear==SIZE-1))
	{
		printf("OVERFLOW\n");
		return;
	}
	else if(q->front==-1 && q->rear==-1)
	{
		q->front++;
		q->rear++;
		q->a[q->rear]=x;
	}
	else
	{
		q->rear++;
		q->a[q->rear]=x;
	}
}

int deque(struct queue *q)
{   int x;
	if((q->front==-1) && (q->rear==-1))
	{
		printf("UNDERFLOW\n");
		return -1;
	}
	else if(q->front == q->rear)
	{
		x=q->a[q->front];
		q->front = q->rear = 0;
		return x;
	}

	else
	{
		x=q->a[q->front];
		q->front++;
		return x;
	}

}


int size(struct queue *q)
{
	int i,count=0;
	for(i=q->front;i<=q->rear;i++)
		count++;
	return count;
}


int pop(struct queue *q)
{  
	 int i,m,x;
	for(i=0;i<=(size(q)-2); i++)
	{
		x=deque(q);
		enque(q,x);
	}
	m=deque(q);
	return m;
}

void display(struct queue *q)
{   int i;
	for(i=q->front;i<=q->rear;i++)
		{
			printf("%d \t", q->a[i]);
		}
}

int main()
{	struct queue q;
	init_queue(&q);
	int op,a,t;
	do
	{
		printf("\n1:Insert element\n2:Delete element\n3:Display elements\n4:EXIT\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: scanf("%d",&a);
				enque(&q,a);
				break;

			case 2: t=pop(&q);
					  printf("Deleted element:%d",t);
				break;

			case 3: display(&q);
				break;

			case 4: exit(1);

			default: printf("WRONG CHOICE");
		}
	}
	while(1);
	return 0;
}
/*
1:Insert element                                                                                                                                       
2:Delete element                                                                                                                                       
3:Display elements                                                                                                                                     
4:EXIT                                                                                                                                                 
1                                                                                                                                                      
5                                                                                                                                                      
                                                                                                                                                       
1:Insert element                                                                                                                                       
2:Delete element                                                                                                                                       
3:Display elements                                                                                                                                     
4:EXIT                                                                                                                                                 
1                                                                                                                                                      
7                                                                                                                                                      
                                                                                                                                                       
1:Insert element                                                                                                                                       
2:Delete element                                                                                                                                       
3:Display elements                                                                                                                                     
4:EXIT                                                                                                                                                 
2                                                                                                                                                      
Deleted element:7                                                                                                                                      
1:Insert element                                                                                                                                       
2:Delete element                                                                                                                                       
3:Display elements                                                                                                                                     
4:EXIT                                                                                                                                                 
3                                                                                                                                                      
5                                                                                                                                                      
1:Insert element                                                                                                                                       
2:Delete element                                                                                                                                       
3:Display elements        
4:EXIT                                                                                                                                                 
4
*/
