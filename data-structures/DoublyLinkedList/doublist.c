#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
struct node *next,*prev;
};
struct node *START=NULL;
void insert_Beg(int val)
{
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->info=val;
 	if(START==NULL)
 	{
  		START=newnode;
  		newnode->next=NULL;
                newnode->prev=NULL;
 	}
 	else
 	{       struct node* ptr;
                ptr=START;
                START=newnode;
                newnode->next=ptr;
                ptr->prev=newnode;
  		newnode->prev=NULL;
  		
  	}
 }
void insert_End(int val)
{
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->info=val;
 	if(START==NULL)
 	{
  		START=newnode;
  		newnode->next=NULL;
                newnode->prev=NULL;
 	}
 	else
 	{       struct node* ptr;
                ptr=START;
  		while(ptr->next!=NULL)
                {
                   ptr=ptr->next;
                 }
                 ptr->next=newnode;
                 newnode->prev=ptr;
                 newnode->next=NULL;
  		
  	}
 }
void insert_After(int val,int x)
{       
        if(START==NULL)
        { printf("\n List is empty");}
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->info=val;
        struct node* ptr;
        ptr=START;
        while(ptr->info!=x&&ptr!=NULL)
        { 
           ptr=ptr->next;
           }
           if(ptr!=NULL)
           { newnode->next=ptr->next;
              newnode->prev=ptr;
              ptr->next->prev=newnode;
             ptr->next=newnode;
           }
         else {printf("Node not found\n");}
         
 }        
        
void insert_Before(int val,int x)
{       if(START==NULL)
        { printf("\n List is empty");}
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->info=val;
        struct node* ptr;
        ptr=START;
        while(ptr->info!=x&&ptr!=NULL)
        { 
           ptr=ptr->next;
          }
           if(ptr!=NULL)
           {
           ptr->prev->next=newnode;
           newnode->prev=ptr->prev;
           newnode->next=ptr;
           ptr->prev=newnode;
           }
         	else 
		{
		printf("Node not found\n");
                }
}        
void delete_End()
{       struct node* ptr;
                ptr=START;
 	if(START==NULL)
 	{
            printf("Empty List\n");
 	}

        else if(ptr->next==NULL)
        {  
            printf("\nThe value deleted is %d",ptr->info);
            free(ptr);
            START=NULL;
            
        }
 	else
 	{
  		while(ptr->next!=NULL)
                {
                   ptr=ptr->next;
                 }
                printf("\nThe value deleted is %d",ptr->info);
                ptr->prev->next=NULL;
                free(ptr);
  	}
 }
void delete_Beg()
{       
        struct node* ptr;
                ptr=START;
 	if(START==NULL)
 	{
            printf("Empty List\n");
 	}
         else if(ptr->next==NULL)
        {   printf("\nThe value deleted is %d",ptr->info);
            free(ptr);
            START=NULL;
        }
 	else 
 	{
                struct node* ptr;
                ptr=START;
  		START=ptr->next;
                ptr->next->prev=NULL;
                printf("\nThe value deleted is %d",ptr->info);
                free(ptr);
  	}
 }
void delete_Before(int val)
{
 if(START==NULL)
 	{
            printf("Empty List\n");
            return;
 	}
    struct node* ptr,*temp;
        ptr=START;
        while(ptr->info!=val&&ptr!=NULL)
        { 
           ptr=ptr->next;
         }
         temp=ptr->prev;
           if(temp==NULL)
            { printf("\nIMPOSSIBLE");
               }
           else if(temp->prev==NULL)
            { 
                   delete_Beg();
             }
             else
             {
                       ptr->prev=temp->prev;
                       temp->prev->next=ptr;
                     printf("\nThe value deleted is %d",temp->info);
                       free(temp);
              }
 }            
void delete_After(int val)
{    if(START==NULL)
 	{
            printf("Empty List\n");
            return;
 	}
    struct node* ptr,*temp;
        ptr=START;
        while(ptr->info!=val&&ptr!=NULL)
        { 
           ptr=ptr->next;
         }
         temp=ptr->next;
           if(temp==NULL)
            { printf("\nIMPOSSIBLE");
               }
           else if(temp->next==NULL)
            { 
                   delete_End();
             }
             else
             {
                       ptr->next=temp->next;
                     temp->next->prev=ptr;
                        printf("\nThe value deleted is %d",temp->info);
                       free(temp);
              }
 }     
void display()
 {
 if(START==NULL)
 	{
  		printf("\nUnderflow");
 	}
 	else
 	{
 	   struct node *ptr;
 	   printf("\nThe entered list is ");
 		ptr=START;
   	while(ptr->next!=NULL)
   	{
     		printf("\t %d",ptr->info);
    		 ptr=ptr->next;
    	}
    	printf("\t %d",ptr->info);
    }
 }    
int main()
 {
  int option,data,node;
  while(1)
  {
    printf("\n1:Insert at the end of List\n2:Insert after a specific node\n3:Insert before a specific node\n4:Delete ending node\n5:Delete before a specfic node\n6:Delete after a specific node\n7:Display List\n8:Insert at the beginning of List\n9:Delete beginning node\n10:Exit\n");
    scanf("%d",&option);
    if(option==1)
    {
    printf("Enter value\n");
    scanf("%d",&data);
    insert_End(data);
    }
    else if(option==2)
    {
     printf("Enter value\n");
    scanf("%d",&data);
    printf("Enter node\n");
    scanf("%d",&node);
    insert_After(data,node);
    }
    else if(option==3)
    {
      printf("Enter value\n");
    scanf("%d",&data);
     printf("Enter node\n");
    scanf("%d",&node);
     insert_Before(data,node);
    }
    else if(option==4)
    {
    delete_End();
    }
    else if(option==5)
    {
    printf("Enter node\n");
    scanf("%d",&node);
    delete_Before(node);
    }
    else if(option==6)
   {
    printf("Enter node\n");
    scanf("%d",&node);
    delete_After(node);
   }
    else if(option==7)
   {
     display();
    }
    else if(option==8)
    {
    printf("Enter value\n");
    scanf("%d",&data);
    insert_Beg(data);
    }
   else if(option==9)
    {
    delete_Beg();
    }
   else if(option==10)
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
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
1
Enter value
5

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
1
Enter value
6

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
2
Enter value
4
Enter node
5

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
3
Enter value
9
Enter node
6

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
1
Enter value
3

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
1
Enter value
2

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
8
Enter value
1

1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
7

The entered list is 	 1	 5	 4	 9	 6	 3	 2
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
4

The value deleted is 2
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
5
Enter node
9

The value deleted is 4
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
6
Enter node
9

The value deleted is 6
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
9

The value deleted is 1
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
7

The entered list is 	 5	 9	 3
1:Insert at the end of List
2:Insert after a specific node
3:Insert before a specific node
4:Delete ending node
5:Delete before a specfic node
6:Delete after a specific node
7:Display List
8:Insert at the beginning of List
9:Delete beginning node
10:Exit
/*


















































