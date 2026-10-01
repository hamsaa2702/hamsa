#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 5

char stack[MAX];
int top = -1;

void push (char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}
int precedence(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/'||x=='%')
        return 2;
    else if (x=='^')
        return 3;
    else
        return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i=0,j=0;
    char ch;
    
    for(i=0; infix[i]!='\0'; i++)
    {
        ch=infix[i];
        if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while(top!=-1 && stack[top]!='(')
                postfix[j++]=pop();
            top--;
        }
        else
        {
            while(top!=-1 && precedence(stack[top])>=precedence(ch))
                postfix[j++]=pop();
            push(ch);
        }
    }
    while(top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
}

int main ()
{
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
} 