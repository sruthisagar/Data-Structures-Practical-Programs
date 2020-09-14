//Circular Queue

#include<stdio.h>
#include<stdlib.h>
#define size 20

int a[size], front=0, rear=0;

void push(int n)
{
	rear=(rear+1)%n;
	if(front==rear)
		printf("Queue overflow\n");
	else
	{
		printf("\nEnter the element to push\n");
		scanf("%d", &a[rear]);
		display();
	}
}

void pop(int n)
{
	if(front==rear)
		printf("Queue underflow\n");
	else
	{
		printf("\nPopped element %d from queue\n", a[front+1]);
		if(rear==1)
			front=rear=0;
		else
			front=(front+1)%n;
		display();
	}
}

void display()
{
	printf("\nThe queue is:\n");

	if(rear==0)
	{
		printf("empty\n");
		return;
	}

	for(int i=front+1; i<=rear; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void main()
{
	int n, choice;
	char ch;
	printf("Enter the size of circular queue\n");
	scanf("%d", &n);
	do
	{
		printf("\nCircular Queue Menu\n___________________\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	push(n);
					break;
			case 2:	pop(n);
					break;
			case 3: display();
					break;
			case 4:	exit(0);
			default:printf("Invalid choice\n");
					
		}
		printf("\nDo you want to continue? [y/n]\n");
		scanf(" %c", &ch);
	}
	while(ch=='Y'||ch=='y');
}