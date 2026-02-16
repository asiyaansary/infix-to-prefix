#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
typedef struct
{
        char items[MAX];
        int top;
}stack;
void initstack(stack *s)
{
        s->top=-1;
}
void push(stack *s,char c)
{
        s->items[++s->top]=c;
}
char pop(stack *s)
{
        return s->items[s->top--];
}
char peek(stack *s)
{
        return s->items[s->top];
}
int precedence(char op)
{
        if(op== '+'|| op== '-')return 1;
	if(op== '*'|| op== '/')return 2;
	if(op== '^')return 3;
        return 0;
}
void reversestring(char *str)
{
	int len=strlen(str);
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		char temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}
void infixtoprefix(char *infix,char *prefix)
{
        stack s;
        initstack(&s);
        reversestring(infix);
        for(int i=0;infix[i]!='\0';i++)
        {
                if(infix[i]=='(')
                {
                        infix[i]=')';
                }
                else if(infix[i]==')')
                {
                        infix[i]='(';
                }
	}
	int j=0;
	for(int i=0;infix[i]!='\0';i++)
        {
                if(isalnum(infix[i]))
                {
                        prefix[j++]=infix[i];
                }
                else if(infix[i]=='(')
                {
                        push(&s,infix[i]);
                }

                else if(infix[i]==')')
                {
                        while(peek(&s)!='(')
                        {
                                prefix[j++]=pop(&s);
                        }
                        pop(&s);
                }
                else
                {
                        while(s.top !=-1 && precedence(peek(&s))>=precedence(infix[i]))
                        {
                                prefix[j++]=pop(&s);
                        }
                        push(&s,infix[i]);
                }
        }
        while(s.top!=-1)
        {
                prefix[j++]=pop(&s);
        }
        prefix[j]='\0';
	reversestring(prefix);
}
int main()
{
        char infix[MAX],prefix[MAX];
        printf("Enter infix expression:");
        scanf("%s",infix);
        infixtoprefix(infix,prefix);
        printf("prefix expression: %s\n",prefix);
        return 0;
}


