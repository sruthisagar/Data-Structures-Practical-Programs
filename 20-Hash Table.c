#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct node
{
  int data;
  struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;

void insert()
{
  int i,key;
  printf("\nEnter the element to be inserted\n");
  scanf("%d",&key);
  i = key%TABLE_SIZE;

  struct node * newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data=key;
  newnode->next = NULL;

  if(head[i] == NULL)
    head[i] = newnode;
  else
  {
    c=head[i];
    while(c->next != NULL)
      c=c->next;
    c->next=newnode;
  }
}

void search()
{
  int key,index;
  printf("\nEnter the element to be searched: ");
  scanf("%d",&key);
  
  index = key%TABLE_SIZE;
  if(head[index] == NULL)
    printf("Element not found\n");
  else
  {
    for(c=head[index]; c!=NULL; c=c->next)
    {
      if(c->data == key)
      {
        printf("Element found at index %d\n", index);
        break;
      }
    }
    if(c==NULL)
      printf("Element not found\n");
  }
}

void display()
{
  int i;
  printf("\n");
  for(i=0; i<TABLE_SIZE; i++)
  {
    printf("H[%d]: ",i);
    if(head[i] == NULL)
      printf("no element\n");
    else
    {
      for(c=head[i]; c!=NULL; c=c->next)
        printf("%d->",c->data);
      printf("\n");
    }
  }
}

void main()
{
  int choice,key,i;
  while(1)
  {
    printf("Hash Table\n__________\n");
    printf("1. Insert\n2. Display\n3. Search\n4. Exit\n");
    printf("\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          insert();
          break;
      case 2:
          display();
          break;
      case 3:
          search();
          break;
      case 4:
          exit(0);
      default:
          printf("\nInvalid choice\n");
    }
    printf("\n");
  }
}