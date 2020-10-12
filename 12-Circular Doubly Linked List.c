// Circular Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL; 

void display()
{
	struct node *ptr;
	if(head == NULL)
		printf("\nThe list is empty");
	else
	{
		printf("\nThe list is:\n");
		ptr = head;
		do
		{
			printf("%d ", ptr->data);       
			ptr = ptr->next;                     
		}
		while(ptr != head);
	}
	printf("\n");
}

void insertAtFront(int x)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL)
		printf("Failed to allocate memory\n");
	else
	{
		newNode->data = x;
		if (head == NULL)
		{
			head = newNode;
			head->next = head->prev = head;
			tail = head;
		}
		else
		{
			newNode->next = head;
			newNode->prev = tail;
			head->prev = tail->next = newNode;
			head = newNode;
		}
	}

	display();
}

void insertAtEnd(int x)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL)
		printf("Failed to allocate memory\n");
	else
	{
		newNode->data = x;
		if (head == NULL)
		{
			head = newNode;
			head->next = head->prev = head;
			tail = head;
		}
		else
		{
			newNode->next = head;
			newNode->prev = tail;
			head->prev = tail->next = newNode;
			tail = newNode;
		}
	}

	display();
}

void deleteFromFront()
{
	struct node* toDelete;

	if(head == NULL)
		printf("\nList underflow\n");
	else if (head == tail)
	{
		toDelete = head;
		head = tail = NULL;
	}
	else
	{
		toDelete = head;
		head = head->next;
		tail->next = head;
		head->prev = tail;

		printf("Deleted %d from list\n", toDelete->data);
		free(toDelete);
	}

	display();
}

void deleteFromEnd()
{
	struct node* toDelete;

	if(head == NULL)
		printf("\nList underflow\n");
	else if (head == tail)
	{
		toDelete = head;
		head = tail = NULL;
	}
	else
	{
		toDelete = tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;

		printf("Deleted %d from list\n", toDelete->data);
		free(toDelete);
	}

	display();
}

void main()
{
	int choice, element;
	char ch;

	do
	{
		printf("\nCircular Doubly Linked List\n__________________________\n");
		printf("1.Insert at Beginning \n2.Insert at End \n3.Delete from Beginning \n4.Delete from End \n5.Display \n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the element\n");
				scanf("%d", &element);
				insertAtFront(element);
				break;

			case 2:
				printf("\nEnter the element\n");
				scanf("%d", &element);
				insertAtEnd(element);
				break;

			case 3:
				deleteFromFront();
				break;

			case 4:
				deleteFromEnd();
				break;

			case 5:
				display();
				break;

			default:
				printf("\nInvalid choice\n");
		}
	printf("\nDo you want to continue? [y/n]\n");
	scanf(" %c", &ch);
	}

	while(ch=='Y' || ch=='y');
	printf("\n");
}
