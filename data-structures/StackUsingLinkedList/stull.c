#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node *next;
 };
 struct node *TOP=NULL;
 int push(int val)
 {
  struct node *newnode;
 	newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->info=val;
 	if(TOP==NULL)
 	{
  		TOP=newnode;
  		newnode->next=NULL;
 	}
 	else
 	{
  		newnode->next=TOP;
  		TOP=newnode;
  	}
 }
 void pop()
 {
   int pop;
 	struct node *newnode;
 	if(TOP==NULL)
 	{
  		printf("\nUnderflow");
 	}
 	else
 	{
 		struct node *ptr;
  		ptr=TOP;
  		TOP=ptr->next;
  		printf("The popped value is %d",ptr->info);
  		free(ptr);
    }
  }
 void display()
 {
 if(TOP==NULL)
 	{
  		printf("\nUnderflow");
 	}
 	else
 	{
 	   struct node *ptr;
 	   printf("\nThe entered stack is ");
 		ptr=TOP;
   	while(ptr->next!=NULL)
   	{
     		printf("%d",ptr->info);
    		 ptr=ptr->next;
    	}
    	printf("%d",ptr->info);
    }
 } 
 void peek()   
 {
  if(TOP==NULL)
 	{
  		printf("\nUnderflow");
 	}
  else
  {
   struct node *ptr;
   ptr=TOP;
   printf("The Top value is %d",ptr->info);
   }
 }  
 
 int main()
 {
  int option,data;
  struct node *TOP;
  while(1)
  {
    printf("\n1:Push an element\n2:Pop an Element\n3:Display Stack\n4:Peek\n5:Exit\n");
    scanf("%d",&option);
    if(option==1)
    {
    printf("Enter value\n");
    scanf("%d",&data);
    push(data);
    }
    else if(option==2)
    {
     pop();
    }
    else if(option==3)
    {
      display();
    }
    else if(option==4)
    {
     peek();
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    
     
 
