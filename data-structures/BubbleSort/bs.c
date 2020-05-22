#include<stdio.h>
void bubblesort(int n,int a[])
{	
	int i,j,temp,sorted=1;
	for(i=0;i<n-1&&sorted==1;i++)
	{	
		sorted=0;
		for(j=0;j<=n-2;j++)
		{
			if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					sorted=1;
				}
		}
	}
	printf("\nThe sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		printf("\t");
	}
}
void main()
{	
	int n,i,a[100];
	printf("\nEnter the size of array\t");
	scanf("%d",&n);
	printf("\nEnter an array of elements\n");
	for(i=0;i<n;i++)
	{	printf("\t");
		scanf("%d",&a[i]);
		
	}
	bubblesort(n,a);
	
}
/*
Enter an array of elements
	23
	12
	56
	45
	69

The sorted array is
12	23	45	56	69	
*/
