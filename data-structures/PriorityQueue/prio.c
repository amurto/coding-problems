/* 
Title: Implementation of Priority Queue
Name: Amurto Basu
Roll No: 8317
Date Of Performance: 3/09/2018
*/ 

#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int info,prio;
	struct queue *next;
};
struct queue *START;
void add()
{
	int x,p;
	struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
	printf(" \nEnter the data and priority\t");
	scanf("%d,%d",&x,&p);
	newnode->info=x;
	newnode->prio=p;
	if(START==NULL)
	{
		newnode->next=NULL;
		START=newnode;
	}
	else
	{
		if(START->prio>newnode->prio)
		{
			newnode->next=START;
                START=newnode;
		}
		else
		{     
                struct queue *ptr;
                ptr=START;
while(ptr->next!=NULL&&ptr->next->prio<=newnode->prio)
			{
 				ptr=ptr->next;
			}
                 newnode->next=ptr->next;
			 ptr->next=newnode;		
		}
	}
}
void delete()
{
	struct queue *ptr;
	if(START==NULL)
     {
 		printf("\nEmpty Queue");
	}
	else
	{
		
		ptr=START;
		START=START->next;
		printf("\nThe deleted element is %d",ptr->info);
		free(ptr);
	}
}
void display()
{
	int i;
	struct queue *ptr;
	ptr=START;
	if(START==NULL)
     {
		printf("\nEmpty Queue");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->info);
			printf("\t%d",ptr->prio);
			ptr=ptr->next;
		}
		
	}
}
void main()
{
	int option;
	do
	{
		printf("\n1.Add \n2.Delete \n3.Display \n4.Exit \n");
		printf("\nEnter the option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: add();
			break;
			case 2: delete();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			break;
			default: printf(" \nError\n");
		}
	}
	while(1);
}
/*
1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
1
 
Enter the data and priority	3,2

1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
1
 
Enter the data and priority	4,3

1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
1
 
Enter the data and priority	5,1

1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
3

5	1
3	2
4	3
1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
2

The deleted element is 5
1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
3

3	2
4	3
1.Add 
2.Delete 
3.Display 
4.Exit 

Enter the option
4
*/
