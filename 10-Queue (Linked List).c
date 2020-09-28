//Queue using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;   
	struct node* next;      
};

struct node* front = NULL;
struct node* rear = NULL;

void display()
{
	struct node* ptr;
	ptr = front;

	if(front == NULL)
		printf("\nThe queue is empty");
	else
	{
		printf("\nThe queue is:\n");
		while(ptr != NULL)
		{
			printf("%d ", ptr->data);       
			ptr = ptr->next;                     
		}
	}
	printf("\n");
}

void insert(int item)
{
	struct node* newNode;    

	newNode = (struct node*) malloc (sizeof(struct node));  
	if(newNode == NULL)  
		printf("Failed to allocate memory\n");     
	else  
	{    
		newNode->data = item; 
		newNode->next = NULL; 

		if(front == NULL)  
			front = rear = newNode;     
		else   
		{  
			rear->next = newNode;  
			rear = newNode;   
		}  
	} 

	display(); 
}

void delete()
{
	struct node* toDelete;  
	if(front == NULL)   
		printf("\nQueue underflow\n");    
	else   
	{  
		toDelete = front;  
		front = front->next;  
		free(toDelete);  
	} 

	display(); 
}

void main()
{
	int choice, item;
	char ch;

	do
	{
		printf("\nQueue Menu\n__________\n");
		printf("1.Insert \n2.Delete \n3.Display \n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the item to be inserted\n");
				scanf("%d", &item);
				insert(item);
				break;

			case 2:
				delete();
				break;

			case 3:
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