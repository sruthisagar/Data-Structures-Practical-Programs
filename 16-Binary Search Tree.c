#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;
 
void delete1();
void insert();
void delete();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t,int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
 
int flag = 1;

void create()
{
    int data;
    printf("\nEnter the data\n");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
}

void search(struct btnode *t)
{
    /* value more than root node value insert at right */
    if ((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    /* value less than root node value insert at left */
    else if ((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

void insert()
{
    create();
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}

void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("\nBinary search tree is empty\n");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}

void delete()
{
    int data;
    if (root == NULL)
    {
        printf("\nBinary search tree is empty\n");
        return;
    }
    printf("\nEnter the value of node to be deleted: ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
}
 
void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("\nBinary search tree is empty.\n");
        return;
    }
    printf("%d ", t->value);
    if (t->l != NULL)    
        preorder(t->l);
    if (t->r != NULL)    
        preorder(t->r);
}
 
void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("\nBinary search tree is empty.\n");
        return;
    }
    if (t->l != NULL) 
        postorder(t->l);
    if (t->r != NULL) 
        postorder(t->r);
    printf("%d ", t->value);
}

void search1(struct btnode *t, int data)
{
    if ((data>t->value))
    {
        t1 = t;
        search1(t->r, data);
    }
    else if ((data<t->value))
    {
        t1 = t;
        search1(t->l, data);
    }
    else if (data==t->value)
    {
        delete1(t);
    }
}
 
void delete1(struct btnode *t)
{
    int k;
    /* To delete leaf node */
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
    /* To delete node having one left hand child */
    else if (t->r == NULL)
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
 
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }
    /* To delete node having right hand child */
    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t = NULL;
        free(t);
        return;
    }
    /* To delete node having two child */
    else if ((t->l != NULL) && (t->r != NULL))  
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k =largest(t->l);
            flag = 2;
        }
        search1(root, k);
        t->value = k;
    }
 
}
 
/* To find the smallest element in the right sub tree */
int smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return(smallest(t->l));
    }
    else    
        return (t->value);
}
 
/* To find the largest element in the left sub tree */
int largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return(largest(t->r));
    }
    else    
        return(t->value);
}

void main()
{
    int choice;
    char ch;

    do
    {
        printf("\nBinary Search Tree\n__________________");
        printf("\n1. Insert a new node");
        printf("\n2. Inorder traversal");
        printf("\n3. Preorder traversal");
        printf("\n4. Postorder traversal");
        printf("\n5. Delete a node\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert();
                    break;

            case 2: printf("\nInorder traversal: ");
                    inorder(root);
                    printf("\n");
                    break;

            case 3: printf("\nPreorder traversal: ");
                    preorder(root);
                    printf("\n");
                    break;

            case 4: printf("\nPostorder traversal: ");
                    postorder(root);
                    printf("\n");
                    break;

            case 5: delete();
                    break;

            default: printf("\nIvalid choice.\n");
        }

        printf("\nDo you want to continue? [y/n]\n");
        scanf(" %c", &ch);
    }

    while(ch=='Y' || ch=='y');
    printf("\n");
}