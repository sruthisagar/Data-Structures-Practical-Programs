//Infix to Postfix

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

int priority(char elem)
{
    if(elem=='(')
        return 0;
    else if(elem=='+' || elem=='-')
        return 1;
    else if(elem=='*' || elem=='/')
        return 2;
    else if(elem=='^')
        return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix)
{
    char ch, elem;
    int k=0;

    for (int i=0; i<strlen(infix); i++)
    {
        ch=infix[i];

        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
        {
            postfix[k] = ch;
            k++;
        }
        else if (ch == ')') 
        {
            while (stack[top] != '(') // pop from stack till (
            {
                postfix[k] = pop();
                k++;
            }
            elem = pop(); // delete (
        } 
        else // operator
        {
            while (priority(stack[top]) >= priority(ch))
            {
                postfix[k] = pop();
                k++;
            }
            push(ch);
        }
    }

    while (top != -1) // pop from stack till empty
    {
        postfix[k] = pop();
        k++;
    }

    postfix[k] = '\0'; // end of postfix
}

int evaluatePostfix(char* postfix)
{
    char ch;
    int op1, op2;
    for (int i=0; i<strlen(postfix); i++)
    {
        ch=postfix[i];

        if(isdigit(ch)) 
            push(ch-'0'); // string to int
        else // operator
        {
            op2 = pop(); 
            op1 = pop();
            switch(ch) 
            {
                case '+':
                    push(op1+op2); 
                    break;
                case '-': 
                    push(op1-op2); 
                    break;
                case '*': 
                    push(op1*op2);
                    break;
                case '/': 
                    push(op1/op2);
                    break;
            }
        }
    }
    return stack[top];
}

void main()
{
    char infix[SIZE], postfix[SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);
    printf("Value after evaluation: %d\n", evaluatePostfix(postfix));

}