#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct polynomial
{
    int exp;
    int coef;
    struct polynomial *next;
};
typedef struct polynomial node;

void insert(int co, int ex, node **poly)
{
    node *newNode, *productNode;

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
            productNode = *poly;
            while (productNode->next != NULL) // point productNode to last node
                productNode = productNode->next;

            productNode->next = newNode;
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

void multiply(node *poly1, node *poly2, node **result)
{
    int newCoef, newExp;
    node *ptr1, *ptr2, *ptr;

    ptr1 = poly1;
    ptr2 = poly2;

    node *productNode = (node *)malloc(sizeof(node));
    productNode->next = NULL;
    productNode->coef = 0; // setting coefficient of first term as 0
    productNode->exp = INT_MAX; // setting exponent of first term as greatest integer
    *result = productNode;

    while (ptr1 != NULL)
    {
        ptr2 = poly2;
        while (ptr2 != NULL)
        {
            ptr = *result;
            newCoef = ptr1->coef * ptr2->coef;
            newExp = ptr1->exp + ptr2->exp;

            while (ptr->next != NULL && ptr->exp > newExp) // finding correct position of product term
            {
                if ((ptr->next)->exp >= newExp)
                    ptr = ptr->next;
                else
                    break;
            }
            if (ptr->exp == newExp) // if exponents are equal, add coefficients
                ptr->coef = ptr->coef + newCoef;
            else if (ptr->exp > newExp) // else, make and place product term at correct postion
            {
                node *productNode = (node *)malloc(sizeof(node));
                productNode->coef = newCoef;
                productNode->exp = newExp;
                productNode->next = ptr->next;
                ptr->next = productNode;
            }

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    node *toDelete;
    ptr = toDelete = *result;
    ptr = ptr->next;
    *result = ptr;
    free(toDelete); // deleting first term of result
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
    node *poly1 = NULL, *poly2 = NULL, *productPoly = NULL;

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

    printf("\nProduct of the two polynomials:\n");
    multiply(poly1, poly2, &productPoly);
    display(productPoly);
}