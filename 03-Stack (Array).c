//Stack

#include <stdio.h>
#include<stdlib.h>
#define size 20

int a[size], top=-1;

void display()
{
	printf("\nThe stack is:\n");

	if(top==-1)
	{
		printf("empty\n");
		return;
	}
	
	for(int i=0;i<=top;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void push(int n)
{
	if(top==n-1)
		printf("Stack overflow\n");
	else
	{
		top++;
		printf("\nEnter the element to push\n");
		scanf("%d", &a[top]);
		display();
	}
}

void pop()
{
	if(top==-1)
		printf("Stack underflow\n");
	else
	{
		printf("\nPopped element %d from stack\n", a[top]);
		top--;
		display();
	}
}

void main()
{
	int n, choice;
	
	printf("Enter the stack size\n");
	scanf("%d", &n);
	while(1)
	{
		printf("\nStack Menu\n__________\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	push(n);
					break;
			case 2:	pop();
					break;
			case 3: display();
					break;
			case 4:	exit(0);
			default:printf("Invalid choice\n");
					
		}
	}	
}