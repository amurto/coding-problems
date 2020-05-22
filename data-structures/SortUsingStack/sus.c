#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct Stack
{
	int a[10];
	int tos;
};

void push(struct Stack *s,int ele)
{

	if(isFull(s)==1)
	{
	printf("Stack is Full\n");
	return;	
	}
	else
	{
	(s->tos)++;
	s->a[s->tos]=ele;
	}
}

int pop(struct Stack *s)
{
	if(isEmpty(s)==-1)
	{
	printf("Stack is Empty\n");
	return -1;	
	}
	else
	{
	int x;
	x=s->a[s->tos];
	s->tos--;
	return x;
	}
}

int isEmpty(struct Stack *s)		 
{
	if(s->tos==-1)
		return (-1);//Stack is Empty
	else
		return 0;//Stack is not Empty
}

int isFull(struct Stack *s)		 
{
	if(s->tos==SIZE)
		return 1;//Stack is Full
	else
		return 0;//Stack is not Full
}

int peek(struct Stack *s)		{
	if(s->tos==-1)
	{
		printf("Stack is Empty\n");
	}
	else
		return s->a[s->tos];
}	

void display(struct Stack *s)
{
	int i;
	if(s->tos==-1)
	{
		printf("No elements to display\n");
		return;
	}
	printf("The stack is:\t");
	for(i=s->tos;i>=0;i--)
	{
		printf(" %d \t",s->a[i]); 
	}
	printf("\n");
}
void sort(struct Stack *os,struct Stack *hs)
{
	int x;
	while(!isEmpty(os))
	{
		x=pop(os);
		while((!isEmpty(hs))&&(peek(hs)<x))
		{
			push(os,pop(hs));
		}
		push(hs,x);
	}
	printf("The sorted stack is \n");
	display(hs);
}
int main()
{
	struct Stack ori,helper;
	int n,a,i;
	ori.tos=-1;
	helper.tos=-1;
	printf("Enter the number of elements to be entered \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter an element\n");
		scanf("%d",&a);
		push(&ori,a);
	}
	printf("The elements in the stack before sorting\n");
	display(&ori);
	sort(&ori,&helper);
	return 0;
}					

/*
Enter the number of elements to be entered                                                                                                             
7                                                                                                                                                      
Enter an element                                                                                                                                       
8                                                                                                                                                      
Enter an element                                                                                                                                       
5                                                                                                                                                      
Enter an element                                                                                                                                       
7                                                                                                                                                      
Enter an element                                                                                                                                       
1                                                                                                                                                      
Enter an element                                                                                                                                       
9                                                                                                                                                      
Enter an element                                                                                                                                       
12                                                                                                                                                     
Enter an element                                                                                                                                       
10                                                                                                                                                     
The elements in the stack before sorting                                                                                                               
The stack is:    10      12      9       1       7       5       8                                                                                     
The sorted stack is                                                                                                                                    
The stack is:    1       5       7       8       9       10      12     
*/
