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
			newnode->next = newnode;
			start=newnode;
		}
		else
		{	
			ptr=start;
			while(ptr->next!= start)
				ptr=ptr->next;
			ptr->next = newnode;
			newnode->next = start;
		}
		printf("Enter the data:\n");
		scanf("%d",&num);
	}
}
void display()
{
	struct node *ptr;
	ptr = start;
	while(ptr->next!=start)
	{
		printf("\t %d", ptr->data);
		ptr=ptr->next;
	}
	printf("\t %d", ptr->data);
}
void insert_beg()
{
	struct node *newnode, *ptr;
	int num;
	printf("Enter the data:\n");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	ptr = start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=newnode;
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
	newnode->next=start;
	ptr = start;
	while(ptr->next!=start)
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
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=start->next;
	free(start);
	start=ptr->next;
}
void delete_end()
{
	struct node *ptr,*preptr;
	ptr = start;
	while(ptr->next != start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}
void delete_node()
{
	struct node *newnode,*ptr,*preptr;
	int val;
	printf("Enter the value of the node which has to be deleted\n");
	scanf("%d", &val);
	ptr = start;
	if(ptr->data == val)
	{
		delete_beg();
	}
	else
	{
		while(ptr->data !=val)
		{
			preptr=ptr;
			ptr=ptr->next;
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
	if(ptr == start)
		start = preptr->next;
	free(ptr);
}
void delete_list()
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		delete_end();
	free(ptr);
}
void main()
{	struct node start;
	int op;
	do
	{
		printf("\nEnter\n");
		printf("1: Create a list\n");
		printf("2: Display the list\n");
		printf("3: Add node at begining\n");
		printf("4: Add node at end\n");
		printf("5: Add node before a given node\n");
		printf("6: Add node after a given node\n");
		printf("7: Delete a node from the begining\n");
		printf("8: Delete a node from the end\n");
		printf("9: Delete a given node\n");
		printf("10: Delete a node after a given node\n");
		printf("11: EXIT\n");
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
			case 11:exit(1);
				break;
			default: printf("WRONG CHOICE"); 
				 break;

		}
	}while(1);
}
/*OUTPUT:
Enter
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
11: EXIT
Enter your option
1
Enter -1 to end
Enter the data:
45
Enter the data:
67
Enter the data:
39
Enter the data:
-1
LINKED LIST CREATED
Enter your option
2
	 45	 67	 39
Enter your option
3
Enter the data:
98
Enter your option
4
Enter the data:
69
Enter your option
5
Enter the data:
17
Enter the value before which the data has to be inserted
45
Enter your option
6
Enter the data:
339
Enter the value after which the data has to be inserted
67
Enter your option
2
	 98	 17	 45	 67	 339	 39	 69
Enter your option
7
Enter your option
8
Enter your option
9
Enter the value of the node which has to be deleted
45
Enter your option
2
	 17	 67	 339	 39
Enter your option
10
Enter the value after which the node has to deleted
339
Enter your option
2
	 17	 67	 339
Enter your option
11
*/
