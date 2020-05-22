#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 10
struct node
{
	char info;
	struct node *left,*right;
};
struct stack
{
	int top;
	struct node *a[10];
};
void init_stack(struct stack* p)
{
	p->top=-1;
}

void push(struct stack *q,struct node *p)
{
	if(q->top==MAX_SIZE-1)
		{	
			printf("\nOverflow");
		}
	else
		{
			q->a[++q->top]=p;
		}
}
struct node *pop(struct stack *s)
{
	return (s->a[s->top--]);
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%c\t",p->info);
		inorder(p->right);
	}
}
int construct(char postfix[])
{
	struct stack s;
	init_stack(&s);
	int i;
	for(i=0;postfix[i]!='\0';i++)
	{
		struct node *p,*x,*y;
		p=(struct node*)malloc(sizeof(struct node));
		x=(struct node*)malloc(sizeof(struct node));
		y=(struct node*)malloc(sizeof(struct node)); 
		p->info=postfix[i];
		p->left=p->right=NULL;
		if(isalnum(postfix[i]))
		{
			push(&s,p);
		}
		else
		{
					
			x=pop(&s);
			y=pop(&s);
			p->left=y;
			p->right=x;
			push(&s,p);
		}
		
	}
	int e;
	e=eval(pop(&s));
	printf("The result is %d\n",e);
}	
int eval(struct node *p)
{
	int t1,t2;
	if(p->left==NULL&&p->right==NULL)
		return (p->info-'0');
	else
	{
		t1=eval(p->left);
		t2=eval(p->right);
		switch(p->info)
		{
			case '+':return(t1+t2);
			case '-':return(t1-t2);
			case '/':return(t1/t2);
			case '*':return(t1*t2);
		}
	}
}


int main()
{
	char post[50];
	printf("\nEnter postfix expression\n");
	gets(post);	
	construct(post);
}

/*
Enter postfix expression
57+
The result is 12
*/


