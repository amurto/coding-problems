#include<stdio.h>
#include<stdlib.h>
struct node
{
  int pow,coeff;
  struct node *next;
  };
  struct node *addnode(struct node *START,struct node *newnode)
  {
    struct node *ptr;
    ptr=START;
    if(START==NULL)
    {
      START=newnode;
      newnode->next=NULL;
      }
      else
       {
        while(ptr->next!=NULL)
        {
          ptr=ptr->next;
          }
          ptr->next=newnode;
          newnode->next=NULL;
         }
         return START;
    }
   struct node *add(struct node *START1,struct node *START2,struct node *START3) 
   {
    struct node *ptr1,*ptr2;
    ptr1=START1;
    ptr2=START2;
    int sum;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
     if(ptr1->pow==ptr2->pow)
     {
      sum=ptr1->coeff+ptr2->coeff;
      struct node *newnode=(struct node*)malloc(sizeof(struct node));
      newnode->coeff=sum;
      newnode->pow=ptr1->pow;
      START3=addnode(START3,newnode);
      ptr1=ptr1->next;
      ptr2=ptr2->next;
      }
      else if(ptr1->pow<ptr2->pow)
      { 
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=ptr2->coeff;
        newnode->pow=ptr2->pow;
        START3=addnode(START3,newnode);
        ptr2=ptr2->next;
        }
        else
        {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=ptr1->coeff;
        newnode->pow=ptr1->pow;
        START3=addnode(START3,newnode);
        ptr1=ptr1->next;
        }
      }
      if(ptr1==NULL)
      {
       while(ptr2!=NULL)
       {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=ptr2->coeff;
        newnode->pow=ptr2->pow;
        START3=addnode(START3,newnode);
        ptr2=ptr2->next;
       }
      }
       if(ptr2==NULL)
      {
       while(ptr1!=NULL)
       {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=ptr1->coeff;
        newnode->pow=ptr1->pow;
        START3=addnode(START3,newnode);
        ptr1=ptr1->next;
       }
      } return START3;
}
void display(struct node *START)
{
  if(START==NULL)
  {
   printf("\nNo polynomial entered");
  }
   else
   {  printf("\n");
      struct node *ptr;
      ptr=START;
      printf("\n");
      while(ptr!=NULL)
      {
        if(ptr->pow==1)
         printf("%dX",ptr->coeff);
        else if(ptr->pow==0)
            printf("%d",ptr->coeff);
        else
        printf("%dX%d",ptr->coeff,ptr->pow);
        ptr=ptr->next;
        if(ptr==NULL)
         printf("=0");
        else
         printf("+");
      
      }
   
   }
}
  int main()
  {  
     struct node *start1=NULL;
     struct node *start2=NULL;
     struct node *start3=NULL; 
     printf("\nEnter first polynomial");
     int n,co,power,i;
      printf("\nEnter number of terms\t");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
         struct node *newnode=(struct node*)malloc(sizeof(struct node));
      printf("\nEnter coefficient\t");
       scanf("%d",&co);
        newnode->coeff=co;
      printf("\nEnter power\t");
        scanf("%d",&power);
        newnode->pow=power;
        start1=addnode(start1,newnode);
        }
        printf("\nEnter second polynomial");
      printf("\nEnter number of terms\t");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
         struct node *newnode=(struct node*)malloc(sizeof(struct node));
      printf("\nEnter coefficient\t");
       scanf("%d",&co);
        newnode->coeff=co;
      printf("\nEnter power\t");
        scanf("%d",&power);
        newnode->pow=power;
        start2=addnode(start2,newnode);
        }
        printf("\nThe entered polynomials are");
        display(start1);
        display(start2);
        start3=add(start1,start2,start3);
        printf("\nAdding the two polynomials");
        display(start3);
     }


/*
Enter first polynomial                                                                                                                                 
Enter number of terms   3                                                                                                                              
                                                                                                                                                       
Enter coefficient       2                                                                                                                              
                                                                                                                                                       
Enter power     3                                                                                                                                      
                                                                                                                                                       
Enter coefficient       4                                                                                                                              
                                                                                                                                                       
Enter power     2                                                                                                                                      
                                                                                                                                                       
Enter coefficient       7                                                                                                                              
                                                                                                                                                       
Enter power     1                                                                                                                                      
                                                                                                                                                       
Enter second polynomial                                                                                                                                
Enter number of terms   4                                                                                                                              
                                                                                                                                                       
Enter coefficient       6                                                                                                                              
                                                                                                                                                       
Enter power     3                                                                                                                                      
                                                                                                                                                       
Enter coefficient       2                                                                                                                              
                                                                                                                                                       
Enter power     2                                                                                                                                      
                                                              

                                                                                         
Enter coefficient       7                                                                                                                              
                                                                                                                                                       
Enter power     1  
Enter coefficient       9                                                                                                                              
                                                                                                                                                       
Enter power     0                                                                                                                                      
                                                                                                                                                       
The entered polynomials are                                                                                                                            
                                                                                                                                                       
2X3+4X2+7X=0                                                                                                                                           
                                                                                                                                                       
6X3+2X2+7X+9=0                                                                                                                                         
Adding the two polynomials                                                                                                                             
                                                                                                                                                       
8X3+6X2+14X+9=0             */          