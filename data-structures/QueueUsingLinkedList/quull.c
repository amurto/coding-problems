#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node 
{
 struct node *next;
int info;
};
struct node *FRONT=NULL;
struct node *REAR=NULL;
void enque(int val)
{
  	struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	struct node *ptr;
 	newnode->info=val;
	if(FRONT==NULL&&REAR==NULL)
	{
  		FRONT=newnode;
		REAR=newnode;
                REAR->next=NULL;
	}
	else
	{
   		REAR->next=newnode;
                REAR=newnode;
                REAR->next=NULL;
	}  
}
void deque()
{
 	struct node *ptr=FRONT;
        int val;
  	if(FRONT==NULL&&REAR==NULL)
	{ 
  		printf("\nQueue is empty");
                 return;
  	}
  	else if(FRONT==REAR)
        {
           FRONT=REAR=NULL;
           }
         else
        {
  		FRONT=FRONT->next;
         }
              val=ptr->info;
                printf("\nThe deleted value is %d",val);
  		free(ptr);
}
void Isempty()
{ 
   if(FRONT==NULL&&REAR==NULL)
               printf("\nQueue is empty");
    else
               printf("\nQueue has values");
}
void display()
{
        struct node *ptr;
	if(FRONT==NULL&&REAR==NULL)
	{
               printf("\nQueue is empty");
	}
	else
	{
                ptr=FRONT;
 		while(ptr!=NULL)
                {  
                     printf("%d",ptr->info);
                     ptr=ptr->next;
                }
         }
}
int main()
 {
  int option,data;
  struct node ;
  while(1)
  {
    printf("\n1:Enter element in queue\n2:Delete element from queue\n3:Display Queue\n4:Is Queue empty?\n5:Exit\n");
    scanf("%d",&option);
    if(option==1)
    {
    printf("Enter value\n");
    scanf("%d",&data);
    enque(data);
    }
    else if(option==2)
    {
     deque();
    }
    else if(option==3)
    {
      display();
    }
    else if(option==4)
    {
      Isempty();
     }
    else if(option==5)
    {
    return 0;
    }
    else
    {
    printf("\nInvalid option");
    }
  }
    return 0;
}
 
 /*

1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
1
Enter value
4

1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
1
Enter value
5

1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
1
Enter value
6

1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
2

The deleted value is 4
1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
3
56
1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
4

Queue has values
1:Enter element in queue
2:Delete element from queue
3:Display Queue
4:Is Queue empty?
5:Exit
5

*/
 
 
 
     
    
