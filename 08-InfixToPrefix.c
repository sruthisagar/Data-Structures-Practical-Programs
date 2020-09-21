//Infix to Prefix

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 50

char stack[SIZE];
int top=-1;

void push(char elem) 
{ 
    top++;
    stack[top]=elem;
}

char pop() 
{ 
    top--;
    return stack[top+1];
}

void getReverse(char* exp, char* rev)
{
	for (int i=0; i<strlen(exp); i++)
		push(exp[i]);

	for (int i=0; i<strlen(exp); i++)
		rev[i]=pop();
}

int priority(char elem)
{
    if(elem=='(')
        return 0;
    else if(elem=='+' || elem=='-')
        return 1;
    else if(elem=='*' || elem=='/')
        return 2;
    return 0;
}

void infixToPrefix(char* infix, char* reverse, char* intermediate, char* prefix)
{
    char ch, elem;
    int k=0;

    getReverse(infix, reverse);

    for (int i=0; i<strlen(reverse); i++)
    {
        ch=reverse[i];

        if (ch == ')')
            push(ch);
        else if (isalnum(ch))
        {
            intermediate[k] = ch;
            k++;
        }
        else if (ch == '(') 
        {
            while (stack[top] != ')') // pop from stack till )
            {
                intermediate[k] = pop();
                k++;
            }
            elem = pop(); // delete )
        } 
        else // operator
        {
            while (priority(stack[top]) > priority(ch))
            {
                intermediate[k] = pop();
                k++;
            }
            push(ch);
        }
    }

    while (top != -1) // pop from stack till empty
    {
        intermediate[k] = pop();
        k++;
    }

    intermediate[k] = '\0'; // end of intermediate

    getReverse(intermediate, prefix);
    prefix[k] = '\0'; // end of prefix
}

void main()
{
    char infix[SIZE], reverse[SIZE], intermediate[SIZE], prefix[SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, reverse, intermediate, prefix);

    printf("\nPrefix expression: %s\n", prefix);
}