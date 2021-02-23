// Linked List

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;   
	struct node *next;      
}*head;

void display()
{
	struct node *ptr;
	if(head == NULL)
		printf("\nThe list is empty");
	else
	{
		printf("\nThe list is:\n");
		ptr = head;
		while(ptr != NULL)
		{
			printf("%d ", ptr->data);       
			ptr = ptr->next;                     
		}
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
		newNode->next = head;
		head = newNode;
	}

	display();
}

void insertAtEnd(int x)
{
	struct node* newNode, *ptr;

	newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL)
		printf("Failed to allocate memory\n");
	else
	{
		newNode->data = x;
		newNode->next = NULL;

		if(head == NULL)
			head = newNode;
		else
		{
			ptr = head;
			while(ptr->next != NULL) // point ptr to last node
				ptr = ptr->next;

			ptr->next = newNode;
		}
	}
	display();
}

void insertAtPosition(int x, int position)
{
	struct node *newNode, *ptr;

	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL)
		printf("Failed to allocate memory.");
	else
	{
		newNode->data = x; 
		newNode->next = NULL;

		ptr = head;
		for(int i=0; i<position-1; i++) // point ptr to the specified position
		{
			if(ptr == NULL)
			{
				printf("\nInvalid position\n");
				return;
			}
			ptr = ptr->next;
		}

		if(position == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else if(position == 1 && head == NULL)
			printf("\nInvalid position\n");
		else
		{
			newNode->next = ptr->next; 
			ptr->next = newNode;
		}
	}

	display();
}

void deleteFromFront()
{
	struct node* toDelete;

	if(head == NULL)
		printf("\nList underflow\n");
	else
	{
		toDelete = head;
		head = head->next;

		printf("Deleted %d from list\n", toDelete->data);
		free(toDelete);
	}

	display();
}

void deleteFromEnd()
{
	struct node *toDelete, *secondLast;

	if(head == NULL)
		printf("\nList underflow\n");
	else
	{
		toDelete = secondLast = head;

		while(toDelete->next != NULL) // point toDelete to last node
		{
			secondLast = toDelete;
			toDelete = toDelete->next;
		}

		if(toDelete == head)
			head = NULL;
		else
			secondLast->next = NULL; // secondLast is made the last node

		printf("Deleted %d from list\n", toDelete->data);
		free(toDelete);
	}

	display();
}

void deleteFromPosition(int position)
{
	struct node *toDelete, *prevNode;

	if(head == NULL)
		printf("\nList underflow\n");
	else
	{
		toDelete = prevNode = head;

		for(int i=0; i<position; i++) // point toDelete to the specified position
		{
			prevNode = toDelete;
			toDelete = toDelete->next;

			if(toDelete == NULL)
			{
				printf("Invalid position\n");
				return;
			}
		}

		if(toDelete == head)
			head = head->next;

		prevNode->next = toDelete->next;
		toDelete->next = NULL;

		printf("Deleted %d from list\n", toDelete->data);
		free(toDelete);
	}

	display();
}

void main()
{
	int choice, element, position;

	while(1)
	{
		printf("\nLinked List\n___________\n");
		printf("1. Display\n");
		printf("2. Insert at Beginning \n3. Insert at End \n4. Insert at a specified Position \n");
		printf("5. Delete from Beginning \n6. Delete from End \n7. Delete from a specified Position\n8. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				display();
				break;

			case 2:
				printf("\nEnter the element\n");
				scanf("%d", &element);
				insertAtFront(element);
				break;

			case 3:
				printf("\nEnter the element\n");
				scanf("%d", &element);
				insertAtEnd(element);
				break;

			case 4:
				printf("\nEnter the element and position\n");
				scanf("%d%d", &element, &position);
				insertAtPosition(element, position);
				break;

			case 5:
				deleteFromFront();
				break;

			case 6:
				deleteFromEnd();
				break;

			case 7:
				printf("\nEnter the position of the element to be deleted\n");
				scanf("%d", &position);
				deleteFromPosition(position);
				break;

			case 8:
				exit(0);

			default:
				printf("\nInvalid choice\n");
		}
	}
	printf("\n");
}