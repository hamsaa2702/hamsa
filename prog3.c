#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push (int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main ()
{
    char postfix[MAX];
    int i, op1, op2, result;
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    for(i=0; postfix[i]!='\0'; i++)
    {
        if(isdigit(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch(postfix[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = pow(op1, op2); break;
                default: printf("Invalid operator: %c\n", postfix[i]); return 1;
            }
            push(result);
        }
    }
    
    printf("Result: %d\n", pop());
    return 0;
}