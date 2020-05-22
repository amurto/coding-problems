#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *left,*right;
  int info;
};
struct node *ROOT=NULL;
void insert(int val)
{
 	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=val;
        newnode->left=NULL;
 	newnode->right=NULL;
	if(ROOT==NULL)
 	{
		ROOT=newnode;
	}
	else
	{
 		struct node *ptr,*parent;
		ptr=ROOT;
		while(ptr!=NULL)
		{	
			if(val<ptr->info)
			{
				parent=ptr;
				ptr=ptr->left;
			}
			else
			{
				parent=ptr;
				ptr=ptr->right;
			}
		}
	if(val<parent->info)
	{
		parent->left=newnode;
	}
	else
	{
		parent->right=newnode;
	}
	}
}
void delete(int val)
{	
	struct node *ptr,*parent;
	ptr=ROOT;
	parent=NULL;
	int flag;
	flag=0;
	while(ptr!=NULL)
	{
		if(ptr->info==val)
		{
			flag=1;
			break;
		}
		else if(val<ptr->info)
		{
			parent=ptr;
			ptr=ptr->left;
		}
		else
		{
			parent=ptr;
			ptr=ptr->right;
		}
	}
	if(flag==0)
	{
		printf("\nValue not found");
	}
	else
	{
		if(ptr->left==NULL&&ptr->right==NULL)
		{
			if(parent==NULL)
				ROOT=NULL;				
			else if(ptr==parent->left)
			{
				parent->left=NULL;
				free(ptr);
			}
			else
			{
				parent->right=NULL;
				free(ptr);
			}
		}
		else if(ptr->left==NULL&&ptr->right!=NULL)
		{
			if(parent->left==ptr)
			{
				parent->left=ptr->right;
			}
			else
			{
				parent->right=ptr->right;
			}
		}
		else if(ptr->right==NULL&&ptr->left!=NULL)
		{
			if(parent->right==ptr)
			{
				parent->right=ptr->left;
			}
			else
			{
				parent->left=ptr->left;
			}
		}
		else
		{
			struct node *r;
			int n;
			r=ptr->left;
			while(r->right!=NULL)
			{
				r=r->right;
			}
			n=r->info;
			delete(n);
			ptr->info=n;
		}
	}
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d\t",p->info);
		inorder(p->right);
	}
}
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t",p->info);
	}
}
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d\t",p->info);
		preorder(p->right);
		preorder(p->left);
	}
}
int Total(struct node *p)
{
	if(p==NULL)
		return 0;
	else
		return(Total(p->left)+Total(p->right)+1);
}
int countLeaf(struct node *p)
{
       if(p==NULL)
		return 0;
	else if(p->left==NULL&&p->right==NULL)
		return 1;
	else
		return(countLeaf(p->left)+countLeaf(p->right)+0);	
}
void Min()
{
	if(ROOT==NULL)
	{
		printf("\nEmpty tree");
	}
	else
	{
		struct node *ptr,*parent;
		ptr=ROOT;
		while(ptr!=NULL)
		{
			parent=ptr;
			ptr=ptr->left;
		}
  		printf("\n%d",parent->info);
	}
}  
void Max()
{
	if(ROOT==NULL)
	{
		printf("\nEmpty tree");
	}
	else
	{
		struct node *ptr,*parent;
		ptr=ROOT;
		while(ptr!=NULL)
		{
			parent=ptr;
			ptr=ptr->right;
		}
  		printf("\n%d",parent->info);
	}
}  				
int main()
{ 
	int data,opt;
        while(1)
	{
        printf("\n1.Create a node\n2.Delete a node\n3.Inorder Traversal\n4.Postorder Traversal\n5.Preorder Traversal\n6.Display total number of nodes\n7.Display total number of leaf nodes\n8.Display total number of non-leaf nodes\n9.Display largest node\n10.Display smallest node\n11.Exit\n");
	scanf("%d",&opt);
	if(opt==1)
	{
		printf("\nEnter data: ");
		scanf("%d",&data);
		insert(data);
	}
	else if(opt==2)
	{
		printf("\nEnter data: ");
		scanf("%d",&data);
		delete(data);
	}
	else if(opt==3)
	{
		inorder(ROOT);	
	}
	else if(opt==4)
	{
		postorder(ROOT);	
	}
	else if(opt==5)
	{
		preorder(ROOT);	
	}
	else if(opt==6)
	{
		int total;
		total=Total(ROOT);
		printf("%d",total);
	}
	else if(opt==7)
	{
		int countleaf;
		countleaf=countLeaf(ROOT);
		printf("%d",countleaf);
	}
	else if(opt==8)
	{
		int t,c,n;
		t=Total(ROOT);
		c=countLeaf(ROOT);
		n=t-c;
		printf("%d",n);
	}
	else if(opt==9)
	{
		Max();
	}
	else if(opt==10)
	{
		Min();
	}
	else if(opt==11)
	{
		return 0;
	}
	else
	{
		printf("\nInvalid option entered");
	}
	}
	return 0;
}

/*

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
1

Enter data: 45

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
1

Enter data: 56

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
1

Enter data: 34

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
1

Enter data: 23

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
1

Enter data: 89

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
1

Enter data: 10

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
2

Enter data: 10

1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
3
23	34	45	56	89	
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
4
23	34	89	56	45	
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
5
45	56	89	34	23	
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
6
5
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
7
2
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
8
3
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
9

89
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
10

23
1.Create a node
2.Delete a node
3.Inorder Traversal
4.Postorder Traversal
5.Preorder Traversal
6.Display total number of nodes
7.Display total number of leaf nodes
8.Display total number of non-leaf nodes
9.Display largest node
10.Display smallest node
11.Exit
11
*/






















