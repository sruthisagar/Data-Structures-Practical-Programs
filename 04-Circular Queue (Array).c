#include<stdio.h>
#include<stdlib.h>

#define size 5

int a[size], front=0, rear=0, n;

void display ()
{
	int i;
	printf ("\nThe queue is:\n");

	if (front==rear)
		printf ("empty\n");
	else
	{
		for (i = front+1; i != rear; i = (i + 1) % n)
			printf ("%d ", a[i]);
		printf ("%d\n", a[i]);
	}
}

void push()
{
	if(front==(rear+1)%n)
		printf("Queue overflow\n");
	else
	{
	   	rear=(rear+1)%n;
		printf("\nEnter the element to push\n");
		scanf("%d", &a[rear]);
		display();
	}
}

void pop()
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

void main()
{
	int choice;

	printf("Enter the size of circular queue\n");
	scanf("%d", &n);
	while(1)
	{
		printf("\nCircular Queue\n______________\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit \n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	push();
					break;
			case 2:	pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			default:printf("Invalid choice\n");
					
		}
	}
}