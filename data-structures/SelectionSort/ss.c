#include<stdio.h>
int smal(int a[],int k,int n)
{
	int pos=k,small=a[k],i;
	for(i=k+1;i<n;i++)
	{
		if(a[i]<small)
		{
			small=a[k];
			pos=i;
		}
	}
	return pos;
}
void selectionSort(int a[],int n)
{
	int k,pos,temp;
	for(k=0;k<n;k++)
	{	
		pos=smal(a,k,n);
		temp=a[k];
		a[k]=a[pos];
		a[pos]=temp;
	}
	printf("\nThe sorted array is\n");
	for(k=0;k<n;k++)
	{
		printf("%d",a[k]);
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
	selectionSort(a,n);
	
}
				
