// Check whether a doubly linked list of characters is palindrome or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node* prev;
	struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void display()
{
	struct node* ptr;
	if(head == NULL)
		printf("\nThe list is empty");
	else
	{
		ptr = head;
		while(ptr != NULL)
		{
			printf("%c", ptr->data);       
			ptr = ptr->next;                     
		}
	}
}

void insert(char ch)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		printf("Failed to allocate memory\n");
	}
	else
	{
		newNode->data = ch;
		if (head == NULL)
		{
			newNode->next = newNode->prev = NULL;
			head = tail = newNode;
		}		
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			newNode->next = NULL;
			tail = newNode;
		}

	}
}

void checkPalindrome(int size)
{
	struct node* ptr1 = head;
	struct node* ptr2 = tail;

	display();
	for (int i=0; i<size; i++)
	{
		if (ptr1->data != ptr2->data)
		{
			printf(" is not palindrome\n");
			return;
		}
		else
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->prev;
		}
	}
	printf(" is palindrome\n");
}

void main()
{
	char str[50];

	printf("Enter a string\n");
	scanf("%s", str);

	for (int i=0; i<strlen(str); i++)
		insert(str[i]);
	
	checkPalindrome(strlen(str));
}