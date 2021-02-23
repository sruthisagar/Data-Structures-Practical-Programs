#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL, *newNode = NULL, *parent;

void createNode()
{
    int item;
    printf("\nEnter the data\n");
    scanf("%d", &item);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
}

void searchAndInsert(struct node *ptr)
{
    /* value more than root node value insert at right */
    if ((newNode->data > ptr->data) && (ptr->right != NULL))
        searchAndInsert(ptr->right);
    else if ((newNode->data > ptr->data) && (ptr->right == NULL))
        ptr->right = newNode;
    /* value less than root node value insert at left */
    else if ((newNode->data < ptr->data) && (ptr->left != NULL))
        searchAndInsert(ptr->left);
    else if ((newNode->data < ptr->data) && (ptr->left == NULL))
        ptr->left = newNode;
}

void insert()
{
    createNode();
    if (root == NULL)
        root = newNode;
    else
        searchAndInsert(root);
}

/* To find the smallest element in the right sub tree */
int smallestLeftNode(struct node *ptr)
{
    struct node *temp;
    while (ptr->left != NULL)
    {
        temp = ptr;
        ptr = ptr->left;
    }
    temp->left = NULL;

    return ptr->data;
}

void deleteNode(struct node *toDelete)
{
    int smallest;

    if (parent == NULL || parent == toDelete)
        printf("\nParent node not found\n");
    else
    {
        if (parent->left == toDelete)
        {
            if (toDelete->left == NULL && toDelete->right == NULL)
            {
                parent->left = NULL;
                free(toDelete);
            }
            else if (toDelete->left == NULL)
            {
                parent->left = toDelete->right;
                free(toDelete);
            }
            else if (toDelete->right == NULL)
            {
                parent->left = toDelete->left;
                free(toDelete);
            }
            else
            {
                if (toDelete->right->left != NULL)
                {
                    smallest = smallestLeftNode(toDelete->right);
                    toDelete->data = smallest;
                }
                else
                {
                    toDelete->data = toDelete->right->data;
                    toDelete->right = toDelete->right->right;
                }
            }
        }

        if (parent->right == toDelete)
        {
            if (toDelete->left == NULL && toDelete->right == NULL)
            {
                parent->right = NULL;
                free(toDelete);
            }
            else if (toDelete->left == NULL)
            {
                parent->right = toDelete->right;
                free(toDelete);
            }
            else if (toDelete->right == NULL)
            {
                parent->right = toDelete->left;
                free(toDelete);
            }
            else
            {
                if (toDelete->right->left != NULL)
                {
                    smallest = smallestLeftNode(toDelete->right);
                    toDelete->data = smallest;
                }
                else
                {
                    toDelete->data = toDelete->right->data;
                    toDelete->right = toDelete->right->right;
                }
            }
        }
    }
}

void searchAndDelete(struct node *ptr, int item)
{
    if (item > ptr->data)
    {
        parent = ptr;
        searchAndDelete(ptr->right, item);
    }
    else if (item < ptr->data)
    {
        parent = ptr;
        searchAndDelete(ptr->left, item);
    }
    else if (item == ptr->data)
        deleteNode(ptr);
    // else
    //     printf("\nItem not found\n");
}

void delete ()
{
    int item;
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\nEnter the item to be deleted\n");
    scanf("%d", &item);
    parent = root;
    searchAndDelete(root, item);
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void display(struct node *ptr)
{
    if (ptr == NULL)
        printf("\nTree is empty");
    else
    {
        printf("\nInorder traversal:\n");
        inorder(ptr);
        printf("\n\nPreorder traversal:\n");
        preorder(ptr);
        printf("\n\nPostorder traversal:\n");
        postorder(ptr);
    }
    printf("\n");
}

void main()
{
    int choice;

    while (1)
    {
        printf("\nBinary Search Tree\n__________________");
        printf("\n1. Insert a node \n2. Display \n3. Delete a node \n4. Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display(root);
                break;

            case 3:
                delete ();
                break;

            case 4:
                exit(0);

            default:
                printf("\nIvalid choice.\n");
        }
    }
}