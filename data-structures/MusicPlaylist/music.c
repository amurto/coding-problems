#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct music
{
		char name[10],artist[10];
		int prio;
		int date, month,year;
		struct music *prev,*link;
};
struct music *start1,*start2,*start3;
struct music *ptr1,*ptr2,*ptr3;
int z=0;

// add new song in the local list one after the another
void addsongs()
{
	int d,m,y;
	struct music *newnode;
	newnode=(struct music*)malloc(sizeof(struct music));
	printf("\n enter the name of the music");
	gets(newnode->name);
	printf("\n enter the name of te artist");
	gets(newnode->artist);
	printf("\n enter the date ,month,year");
	scanf("%d%d%d",&d,&m,&y);
	newnode->date=d;
	newnode->month=m;
	newnode->year=y;
	if(start1==NULL)  //to add a song if none are present in the list
	{
		start1=newnode;
		ptr1=start1;
		newnode->prev=NULL;
		newnode->link=NULL;	
		z++;
	}
	else    // songs will get added to the list one behind another
	{
		ptr1->link=newnode;
		newnode->prev=ptr1;
		newnode->link=NULL;
		ptr1=newnode;
		z++;
	}
	
	
}
void delet()
{
	struct music*q;
	int found=0;
	char sname [10];
	printf(" enter the song name to be deleted");
	gets(sname);

		while(ptr1->link!=NULL)
		{
				if(strcmp(sname,ptr1->name))
			{
		
				if(start1==NULL)//the list is empty
				{
					printf("\n music list is empty \n");
				}
				else
				{
	  
					if(start1==ptr1)//if the deleted song is first in the list
					{
						start1=NULL;
						printf(" \nsong deleted\n");
						free(ptr1);
						ptr1=start1;
						z--;
						found=1;
						break;
					}
					else
					{
	 
						if(ptr1->link==NULL)// if the deleted song is last in the list
						{
							ptr1->prev->link=NULL;
							printf(" \n song deleted\n");
							free(ptr1);
							ptr1=start1;
							z--;
							found=1;
							break;	
						}
						else   // if the song is any where inbetween of the list 
						{
							ptr1=q;
							ptr1->prev->link=ptr1->link->prev;
							free(q);
							ptr1=start1;
							printf(" \nsong deleted\n");
							z--;
							found=1;
							break;
						}
				
					}
				
				}
			}

		else    // to increament ptr1
			ptr1=ptr1->link;
		}
		
		// to check if the song is found or not
		if (found==1)
		printf(" \n song was found and deleted\n");
		else
		printf(" \n the song was not found in the list\n");
}

display()  // to display all the songs in the list in te phone
{
	struct music *t;
	t=start1;
	int e=1;
	if(start1 ==NULL)
	printf("\n list is empty\n");
	else
	{
	
		while(t->link!=NULL)
		{
			printf(" \n %d .the name of the song  = \n",e++);
			puts(t->name);
			printf(" \n the name of the artist  =\n");
			puts(t->artist);
		
		}
			printf(" \n %d .the name of the song  = \n",e++);
			puts(t->name);
				printf(" \n the name of the artist  =\n");
			puts(t->artist);
	}
}


void addplay()
{
	
	char sname[10];
	printf(" \nthe list of all the songs are\n");
	display();  // pass the pointer to the dislay function to display the main list for displaying the song
	printf(" \n enter the song which will go to the playlist\n");		// enterthe song which should be addedin the playlist
	gets(sname);
	ptr1=start1;
	struct music *newnode;
	newnode=(struct music *)malloc(sizeof(struct music));   //creating a newnode for the playlist whose starting will be pinted by start2 pointer
	while(ptr1->link!=NULL)
	{
		if(strcmp(sname,ptr1->name))		// searching for the song int the min playlist
		break;
		else
		ptr1=ptr1->link;
	}
		if(start2==NULL)  //to add a song if none are present in the playlist
	{
		start2=newnode;
		ptr2=start2;
		newnode->prev=NULL;
		newnode->link=NULL;	
		strcpy(ptr2->name,ptr1->name);
		strcpy(ptr2->artist,ptr1->artist);
		ptr2->date=ptr1->date;
		ptr2->month=ptr1->month;
		ptr2->year=ptr1->year;
	}
	else    // songs will get added to the playlistlist one behind another
	{
		ptr2->link=newnode;
		newnode->prev=ptr2;
		newnode->link=NULL;
		ptr2=newnode;
		strcpy(ptr2->name,ptr1->name);
		strcpy(ptr2->artist,ptr1->artist);
		ptr2->date=ptr1->date;
		ptr2->month=ptr1->month;
		ptr2->year=ptr1->year;
	}
	
} 

displayplay()		//whil display the playlist
{
		struct music *t;
	t=start2;
	int e=1;
	if(start2 ==NULL)
	printf("\n list is empty\n");
	else
	{
	
		while(t->link!=NULL)
		{
			printf(" \n %d .the name of the song  = \n",e++);
			puts(t->name);
			printf(" \n the name of the artist  =\n");
			puts(t->artist);
		
		}
			printf(" \n %d .the name of the song  = \n",e++);
			puts(t->name);
				printf(" \n the name of the artist  =\n");
			puts(t->artist);
	}
}

priority()		// will assign the priority in which songs are going to be played
{
	int temp,x;
	printf("\n entet the the priority\n");
	ptr2=start2;
	displayplay();
	while(ptr2->link!=NULL)		//entering the priority
	{
		printf("\n enter the priority of the song \n");
		scanf("%d",&x);
		ptr2->prio=x;
		ptr2=ptr2->link;
	}
	printf("\n enter the priority of the song \n");
	scanf("%d",&x);
	ptr2->prio=x;
	while(ptr2->link!=NULL)		// sorting according to the priority
	{
		if(ptr2->prio > ptr2->link->prio)
		{
			temp=ptr2->prio;
			ptr2->link->prio=ptr2->prio;
			ptr2->prio=temp;
		}
		displayplay(); 		//display songs accoring to the priority
	}
}

deletplay()		// to delet a song from the playlist created by entering the priority
{
	int x;
	printf("\n enter the number of the song which want to delet from the playlist\n");
	scanf("%d",&x);
	ptr2=start2;
	if(start2==NULL)
	printf("\n playlist is empty\n");
	else
	while (ptr2->prio!=x)
	{
		if(x==1)		// if the song entered is first in the list
		{
			start2=start2->link;
			while(ptr2->link!=NULL)
			{
				ptr2->prio=ptr2->prio-1;		// after deleting the song new priorities will be assign to the remaining song in the playlist
				ptr2=ptr2->link;	
			}
			free(ptr2);		// clearing memory of the song in the playlist but the song will remain in the maim list
			displayplay();
		}
		else
		if(ptr2->link==NULL)		// if the songs priority is last which needs to be deleted
		{
			ptr2->prev->link=NULL;
			free(ptr2);
			displayplay();
		}
		else		// if the songs needs to be added in between the list
		{
			ptr2->prev->link=ptr2->link;
			ptr2->link->prev=ptr2->prev;
			free(ptr2);
			ptr2=start2;
				while(ptr2->link!=NULL)		// new priorities will get assigned to the remaining un the playlist
			{
				ptr2->prio=ptr2->prio-1;
				ptr2=ptr2->link;	
			}
			free(ptr2);
			displayplay();
			
		}
	}
}
	
	addinbtwplay()
	{
			char sname[10];
			int x;
		printf(" \nthe list of all the songs are\n");
		display();  // pass the pointer to the dislay function to display the main list for displaying the song
		printf(" \n enter the song which will go to the playlist\n");		// enterthe song which should be addedin the playlist
		gets(sname);
		printf(" \n enter the priority \n");
		scanf("%d",&x);
		ptr2=start2;
		struct music *newnode;
		newnode=(struct music *)malloc(sizeof(struct music));
		newnode->prio=x;
		if(x==1)		//if the song priority is first
		{
			newnode->link=start2;
			newnode->prev=NULL;
			start2=newnode;
				start2=start2->link;
			while(ptr2->link!=NULL)  // new priority is assigned to the emaining songs
			{
				ptr2->prio=ptr2->prio+1;
				ptr2=ptr2->link;	
			}
			displayplay();
		}
		else
		{
		
			while(ptr2->link!=NULL)
			{
				if(ptr2->prio==x)  		//if the song needs to be added in between the list
				{	
					ptr2->prev->link=newnode;
					newnode->prev=ptr2->prev;
					newnode->link=ptr2;
					ptr2->prev=newnode;
					while(ptr2->link!=NULL)		 // new priority is assigned to the emaining songs
					{
						ptr2->prio=ptr2->prio+1;
						ptr2=ptr2->link;	
					}
						displayplay();
				
				}
				else
				ptr2=ptr2->link;
		    }
		  	if(ptr2->link==NULL)		// if the song is added in the last
			{
				newnode->prev=ptr2;
				newnode->link=NULL;
				ptr2->link=newnode;
			}
		}
	}


void main()
{
	int option;
	do
	{
		start1=NULL;
		ptr1=NULL;
		start2=NULL;
		ptr2=NULL;
	
		printf(" \n welcome to the music world\n");
		printf(" \n1.add song to the  main list\n2.delet song from the main list \n3.display the main list ");
		printf("\n4.creat your playlist \n5.delet song from the playlist\n 6.give priority to your playlist\n 7. add more songs in the existing playlist\n 8. exit\n");
		printf("\n enter the options of ur choise\n");
		scanf("%d",option);
		switch(option)
		{
			case 1: addsongs();
					break;
			case 2: delet();
					break;
			case 3: display();
					break;
			case 4: addplay();
					break;
			case 5: deletplay();
					break;
			case 6: priority();
					break;
			case 7: addinbtwplay();
					break;
			case 8: exit(0);
					break;
			default : printf(" \n option does not exist\n");
		

		}
	
	}
		while(1);
}

