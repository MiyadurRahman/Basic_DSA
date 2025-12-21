#include<stdio.h>
#define SIZE 4

int Stack[SIZE];
int Top = -1;

void push(int data)
{
    if(Top==-1)
    {
        Top = 0;
        Stack[Top] = data;
    }
    else if(Top==SIZE-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        Top = Top + 1;
        Stack[Top] = data;
    }
}

void pop()
{
    if(Top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d", Stack[Top]);
        Stack[Top] = 0;
        Top -= 1;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
}
