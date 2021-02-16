#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL, *rptr, *lptr, *parent;
int smallest;

void createTree(struct node *ptr, int item)
{
    int newItem;
    char option;

    if (ptr == NULL)
    {
        ptr = malloc(sizeof(struct node));
        ptr->left = ptr->right = NULL;
        root = ptr;
    }
    ptr->data = item;

    printf("\nDoes the node %d have left subtree? [y/n]\n", item);
    scanf(" %c", &option);
    if (option == 'Y' || option == 'y')
    {
        lptr = malloc(sizeof(struct node));
        ptr->left = lptr;
        printf("\nEnter the item to be inserted\n");
        scanf("%d", &newItem);
        createTree(lptr, newItem);
    }
    else
        ptr->left = NULL;

    printf("\nDoes the node %d have right subtree? [y/n]\n", item);
    scanf(" %c", &option);
    if (option == 'Y' || option == 'y')
    {
        rptr = malloc(sizeof(struct node));
        ptr->right = rptr;
        printf("\nEnter the item to be inserted\n");
        scanf("%d", &newItem);
        createTree(rptr, newItem);
    }
    else
        ptr->right = NULL;

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

struct node *searchParent(struct node *ptr, struct node *parent, int item)
{
    if(ptr != NULL)
    {
        if(ptr->data == item)
        {
            return parent;
        }
        else
        {
            parent = searchParent(ptr->left, ptr, item);
            if(parent != NULL)
                return parent;

            parent = searchParent(ptr->right, ptr, item);
            return parent;
        }
    }
    return NULL;
}

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

void deleteNode(int item)
{
    struct node *toDelete;

    if (root == NULL)
        printf("Tree is empty");
    else
    {
        if (root->right == NULL && root->left == NULL)
        {
            if (root->data == item)
            {
                free(root);
                root = NULL;
            }
            else
                printf("\nItem not found\n");

            return;
        }
        parent = searchParent(root, NULL, item);
        // printf("\nParent: %d\n", parent->data);

        if (parent == NULL)
            printf("\nParent node not found\n");
        else
        {
            if (parent->left != NULL)
            {
                toDelete = parent->left;
                if (toDelete->data == item)
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
            }
            if (parent->right != NULL)
            {
                toDelete = parent->right;
                if (toDelete->data == item)
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
    }
}

void main()
{
    int choice, item;

    while (1)
    {
        printf("\nBinary Tree\n___________");
        printf("\n1.Create tree \n2.Delete \n3.Display \n4.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the data of root node\n");
                scanf("%d", &item);
                createTree(root, item);
                break;

            case 2:
                if (root != NULL)
                {
                    printf("\nEnter the item to be deleted\n");
                    scanf("%d", &item);
                    deleteNode(item);
                }
                else
                    printf("\nTree not created\n");
                break;

            case 3:
                display(root);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }
    }
}