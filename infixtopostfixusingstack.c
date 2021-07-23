#include <stdio.h>
#include <ctype.h>
char stack[100];
int top = -1;

void push(char x)
{
    top = top + 1;
    stack[top] = x;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
}

int main()
{
    char exp[100];
    char *e, x;
    printf("\nEnter the Prefix Expression : ");
    scanf("%s", &exp);
    e = exp;
    printf("\nThe Postfix expression is : ");
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((*e = pop()) != '(')
            {
                printf("%c", *e);
            }
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e = e + 1;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}
