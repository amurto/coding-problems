
/* 
Title: Implementation Of Linked List
Name: Amurto Basu
Roll No: 8317
Date Of Performance: 6/08/2018
*/ 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*start;


void create()
{
	struct node *newnode, *ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter the data:\n");
	scanf("%d", &num);
	while(num!=-1)
	{
		
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data = num;
		if(start==NULL)
		{
			newnode->next = NULL;
			start=newnode;
		}
		else
		{	
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next = newnode;
			newnode->next = NULL;	
			
		}
		printf("Enter the data:\n");
		scanf("%d", &num);
	}
	
}

void display()
{
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL)
	{
		printf("\t %d", ptr->data);
		ptr=ptr->next;
	}
	
}

void insert_beg()
{
	struct node *newnode;
	int num;
	printf("Enter the data:\n");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->next=start;
	start=newnode;
	
}

void insert_end()
{
	struct node *newnode,*ptr;
	int num;
	printf("Enter the data:\n");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->next=NULL;
	ptr = start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=newnode;
	
}

void insert_before()
{
	struct node *newnode,*ptr,*preptr;
	int num,val;
	printf("Enter the data:\n");
	scanf("%d", &num);
	printf("Enter the value before which the data has to be inserted\n");
	scanf("%d", &val);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	ptr = start;
	while(ptr->data != val)
	{
		preptr=ptr;	
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	
}

void insert_after()
{
	struct node *newnode,*ptr,*preptr;
	int num,val;
	printf("Enter the data:\n");
	scanf("%d", &num);
	printf("Enter the value after which the data has to be inserted\n");
	scanf("%d", &val);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	ptr = start;
	while(preptr->data != val)
	{
		preptr=ptr;	
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	
}

void delete_beg()
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	
}

void delete_end()
{
	struct node *ptr,*preptr;
	ptr = start;
	while(ptr->next != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	
}

void delete_node()
{
	struct node *newnode,*ptr,*preptr;
	int val;
	printf("Enter the value of the node which has to deleted\n");
	scanf("%d", &val);
	ptr = start;
	if(ptr->data == val)
	{
		delete_beg();
		
	}
	else
	{
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr->next=ptr;
		}
		preptr->next=ptr->next;
		free(ptr);
		
	}
}


void delete_after()
{
	struct node *newnode,*ptr,*preptr;
	int val;
	printf("Enter the value after which the node has to deleted\n");
	scanf("%d", &val);
	ptr = start;
	preptr=ptr;
	while(preptr->data != val)
	{
		preptr=ptr;	
		ptr=ptr->next;
	}
	preptr->next = ptr->next;
	free(ptr);
	
}


void sortlist()
{
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data=temp;
			} 
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
		if(start==NULL)
		printf("Empty");
		else
		{
			display();
		}
	
}

void search()
{
	struct node *ptr;
	int num, count=0;
	int flag=0;
	printf("Enter data to be found\n");
	scanf("%d",&num);
	ptr=start;
	while(ptr!=NULL)
	{	count=count+1;
		if(ptr->data==num)
		{
			flag=1;
			break;
		}
		ptr=ptr->next;	
	}
	if(flag==1)
	printf("Element found at node %d\n",count);
	else
	printf("NOT FOUND\n");
}

void main()
{	
	int op;
	do
	{
		printf("\n1: Create a list\n");
		printf("2: Display the list\n");
		printf("3: Add node at begining\n");
		printf("4: Add node at end\n");
		printf("5: Add node before a given node\n");
		printf("6: Add node after a given node\n");
		printf("7: Delete a node from the begining\n");
		printf("8: Delete a node from the end\n");
		printf("9: Delete a given node\n");
		printf("10: Delete a node after a given node\n");
		printf("11: Sort the list\n");
		printf("12: Search the element\n");
		printf("13: EXIT\n");
		printf("Enter your option\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: create();
				printf("LINKED LIST CREATED");
				break;
			case 2: display();
				break;
			case 3: insert_beg();
				break;
			case 4: insert_end();
				break;
			case 5: insert_before();
				break;
			case 6: insert_after();
				break;
			case 7: delete_beg();
			        break;
			case 8: delete_end();
				break;
			case 9: delete_node();
				break;
			case 10: delete_after();
				 break;
			case 11: sortlist();
				 break;
			case 12: search();
				 break;
			case 13: exit(1);
				 break;
			default: printf("WRONG CHOICE"); 
				 break;
		}
	}while(1);
}
/*
1: Create a list
2: Display the list
3: Add node at begining
4: Add node at end
5: Add node before a given node
6: Add node after a given node
7: Delete a node from the begining
8: Delete a node from the end
9: Delete a given node
10: Delete a node after a given node
11: Sort the list
12: Search the element
13: EXIT
Enter your option
1
Enter -1 to end
60
20
40
10
-1
LINKED LIST CREATED
Enter your option
2
	 60	 20	 40	 10
Enter your option
3
Enter the data:
25
Enter your option
2
	 25	 60	 20	 40	 10
Enter your option
5
Enter the data:
40
Enter the value before which the data has to be inserted
60
Enter your option
2
	 25	 40	 60	 20	 40	 10
Enter your option
8
Enter your option
2
	 25	 40	 60	 20	 40
Enter your option
11
	 20	 25	 40	 40	 60
Enter your option
12
Enter data to be found
25
Element found at node 2
Enter your option
13
*/


