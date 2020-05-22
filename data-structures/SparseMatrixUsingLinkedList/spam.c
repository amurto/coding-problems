/* 
Title: Sparse Matrix Implementation using Linked List
Name: Amurto Basu
Roll No: 8317
Date Of Performance: 4/09/2018
*/ 

#include <stdio.h>
#include <stdlib.h>
struct Node {
  int row, col, info;
  struct Node *next;
};
void addnode(struct Node** START, struct Node *newnode) {
  struct Node *ptr;
  
  if (START == NULL || *START == NULL)
    *START = newnode;
  else
  {
    for (ptr = *START; ptr->next != NULL; ptr = ptr->next);
  	ptr->next = newnode;
  }
}
void entMatrix(struct Node** START, int dimr, int dimc) {
	int n, val, r, c, i = 0;
	struct Node *newnode;
	printf("\nEnter number of non zero terms in matrix\t");
   scanf("%d", &n);

  while (i < n) {
    printf("\nEnter value,row and column\n");
    scanf("%d,%d,%d", &val, &r, &c);
    if (r >= dimr || c >= dimc) {
      printf("\nEnter row and column values within dimensions");
      continue;
    }
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = val;
    newnode->next = NULL;
    newnode->row = r;
    newnode->col = c;
    addnode(START,newnode);
    i++;
  }
}
void display(struct Node* START, int dimr, int dimc) {
	struct Node *ptr;
   int i, j;

	if (START == NULL)
		return;
	ptr = START;
   for (i = 0; i < dimr; i++) {
		printf("\n");
      for (j = 0; j < dimc; j++) {
			if (ptr != NULL && ptr->row == i && ptr->col == j) {
				printf("\t%d", ptr->info);
				ptr = ptr->next;
			} else
          printf("\t0");
      }
	}
}
int main() {
  int option, dimr, dimc;
  struct Node* START = NULL;
  while (1) {
    printf("\n1.Enter Matrix\n2.Display Matrix\n3.Exit\n");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("\nEnter dimensions of the matrix\n");
        scanf("%d%d", &dimr, &dimc);
        entMatrix(&START, dimr, dimc);
        break;
      case 2:
        display(START, dimr, dimc);
        break;
      case 3:
        exit(1);
        break;
      default:
        printf("\nInvalid option\n");
    }
  }
  return 0;
}
/*
1.Enter Matrix
2.Display Matrix
3.Exit
1

Enter dimensions of the matrix
3
3

Enter number of non zero terms in matrix	6

Enter value,row and column
2,0,0

Enter value,row and column
3,0,1

Enter value,row and column
4,1,1

Enter value,row and column
5,1,2

Enter value,row and column
7,2,0

Enter value,row and column
8,2,2

1.Enter Matrix
2.Display Matrix
3.Exit
2

	2	3	0
	0	4	5
	7	0	8
1.Enter Matrix
2.Display Matrix
3.Exit
3
*/