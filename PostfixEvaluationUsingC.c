#include <stdio.h>
#include<ctype.h>
// int isdigit();
int stack[100];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];
    char *e;
    int n1,n2,n3,x;
    printf("\nEnter Postfix Expression to evaluate : ");
    scanf("%s",exp);
    e = exp;
    while (*e != '\0')
    {
        if(isdigit(*e))
        {
            x = *e - 48; //To Remove Ascii effect
            push(x);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
            }
        e++;
        }
    printf("\nThe result of expression after evaluation :  %d",pop());
    return 0;
}
