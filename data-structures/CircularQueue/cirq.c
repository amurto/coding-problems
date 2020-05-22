
/* 
Title: Static Implementation of Circular Queue
Name: Amurto Basu
Roll No: 8317
Date Of Performance: 30/07/2018
*/ 

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
void enque(struct queue *p,int val)
{
	
	if((p->rear+1)%MAX_SIZE==p->front)
	{
	printf("Overflow \n");
	return;
	}
	else 
	{
p->rear=(p->rear+1)%5;
 		if(p->front==-1)
		{
		p->front++;
		p->a[p->rear]=val;
		}
		else
		{
 		p->a[p->rear]=val;
		}		
	}
}
int deque(struct queue *p)
{
int x;
if(p->front==-1&&p->rear==-1)
{
printf("Underflow \n");
return -1;
}
else
{
x=p->a[p->front];
if(p->front==p->rear)
{p->front=-1;
p->rear=-1;
}
else
{ p->front=(p->front+1)%5;
}
return x;
}
}
void display(struct queue*p)
{
    int i;
    if(p->front!=-1&&p->rear!=-1)
    {   i=p->front;
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
int isFull(struct queue*p)
{if((p->rear+1)%MAX_SIZE==p->front)
  return 1;
else
return 0;
}
int isEmpty(struct queue*p)
{if(p->front==-1&&p->rear==-1)
  return 1;
else
return 0;
}
int main()
{

	char ch;
	int tmp;
	struct queue queue;

	init_queue(&queue);

	while(1)
	{
		printf("\n1. Enter");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Is Full");
		printf("\n5. Is Empty");
		printf("\n6. Exit\n");

		scanf(" %c",&ch);
	 
		if(ch == '1')
		{
			printf("\nAdd Data\t:");
			scanf("%d",&tmp);
			enque(&queue, tmp);
		}	
		if(ch == '2')
		{
			tmp = deque(&queue);
			printf("\nData Deleted: %d",tmp);
		}
		
		if(ch=='3')
		{
			printf("\nData in Queue is\t:");	
			display(&queue);
		}
		if(ch == '4')
		{
			printf((isFull(&queue)) ? "\nQueue is Full" : "\nQueue has Space left");
		}
		if(ch == '5')
		{
			printf((isEmpty(&queue)) ? "\nQueue is Empty" : "\nQueue has values");
		}
		if(ch == '6')
			return 0;
	}
	return 0;
}

/*
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
1                                                                                                                                                      
                                                                                                                                                       
Add Data        :6                                                                                                                                     
                                                                                                                                                       
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
1                                                                                                                                                      
                                                                                                                                                       
Add Data        :7                                                                                                                                     
                                                                                                                                                       
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
1                                                                                                                                                      
                                                                                                                                                       
Add Data        :8           
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
3                                                                                                                                                      
                                                                                                                                                       
Data in Queue is        :678                                                                                                                           
                                                                                                                                                       
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
2                                                                                                                                                      
                                                                                                                                                       
Data Deleted: 6                                                                                                                                        
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
4                                                                                                                                                      
                                                                                                                                                       
Queue has Space left                                                                                                                                   
1. Enter    
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
5                                                                                                                                                      
                                                                                                                                                       
Queue has values                                                                                                                                       
1. Enter                                                                                                                                               
2. Delete                                                                                                                                              
3. Display                                                                                                                                             
4. Is Full                                                                                                                                             
5. Is Empty                                                                                                                                            
6. Exit                                                                                                                                                
6
*/   