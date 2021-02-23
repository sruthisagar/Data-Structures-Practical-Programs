#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    int coef;
    int exp;
    struct polynomial *next;
};

typedef struct polynomial node;

void insert(int co, int ex, node **poly)
{
    node *newNode, *ptr;

    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        printf("Failed to allocate memory\n");
    else
    {
        newNode->coef = co;
        newNode->exp = ex;
        newNode->next = NULL;

        if (*poly == NULL)
            *poly = newNode;
        else
        {
            ptr = *poly;
            while (ptr->next != NULL) // point ptr to last node
                ptr = ptr->next;

            ptr->next = newNode;
        }
    }
}

void sort(node *poly)
{
    node *ptr1, *ptr2;
    int temp;

    for (ptr1 = poly; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr2->exp > ptr1->exp)
            {
                temp = ptr1->exp;
                ptr1->exp = ptr2->exp;
                ptr2->exp = temp;

                temp = ptr1->coef;
                ptr1->coef = ptr2->coef;
                ptr2->coef = temp;
            }
        }
    }
}

void add(node *ptr1, node *ptr2, node **result)
{
    int sum;

    node *sumNode = (node *)malloc(sizeof(node));
    sumNode->next = NULL;
    *result = sumNode;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp > ptr2->exp)
        {
            sumNode->coef = ptr1->coef;
            sumNode->exp = ptr1->exp;
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            sumNode->coef = ptr2->coef;
            sumNode->exp = ptr2->exp;
            ptr2 = ptr2->next;
        }
        else
        {
            sum = ptr1->coef + ptr2->coef;
            if (sum != 0)
            {
                sumNode->coef = sum;
                sumNode->exp = ptr1->exp;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr1 != NULL && ptr2 != NULL)
        {
            sumNode->next = (node *)malloc(sizeof(node));
            sumNode = sumNode->next;
            sumNode->next = NULL;
        }
    }
    while (ptr1 != NULL || ptr2 != NULL)
    {
        sumNode->next = (node *)malloc(sizeof(node));
        sumNode = sumNode->next;
        sumNode->next = NULL;

        if (ptr1 != NULL)
        {
            sumNode->coef = ptr1->coef;
            sumNode->exp = ptr1->exp;
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL)
        {
            sumNode->coef = ptr2->coef;
            sumNode->exp = ptr2->exp;
            ptr2 = ptr2->next;
        }
    }
}

void display(node *poly)
{
    if (poly != NULL)
    {
        while (poly->next != NULL)
        {
            if (poly->coef != 0)
                printf("%ix^%i + ", poly->coef, poly->exp);
            poly = poly->next;
        }
        if (poly->coef != 0)
            printf("%ix^%i", poly->coef, poly->exp);
        printf("\n");
    }
}

void main()
{
    int n1, n2, coef, exp;
    node *poly1 = NULL, *poly2 = NULL, *sumPoly = NULL;

    printf("Enter the number of terms in first polynomial\n");
    scanf("%i", &n1);
    printf("\nEnter the first polynomial\n");
    for (int i=0; i<n1; i++)
    {
        scanf("%i %i", &coef, &exp);
        insert(coef, exp, &poly1);
    }

    printf("\nEnter the number of terms in second polynomial\n");
    scanf("%i", &n2);
    printf("\nEnter the second polynomial\n");
    for (int i=0; i<n2; i++)
    {
        scanf("%i %i", &coef, &exp);
        insert(coef, exp, &poly2);
    }

    sort(poly1);
    sort(poly2);

    printf("\nFirst polynomial:\n");
    display(poly1);
    printf("\nSecond polynomial:\n");
    display(poly2);

    printf("\nSum of the two polynomials:\n");
    add(poly1, poly2, &sumPoly);
    display(sumPoly);
}