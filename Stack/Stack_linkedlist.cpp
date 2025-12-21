#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    ListNode* next;
};

ListNode* Top = NULL;

ListNode* createListNode(int data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(int data)
{
    if(Top==NULL)
    {
        Top = createListNode(data);
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = Top;
        Top = temp;
    }
}


void pop()
{
    if(Top==NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        ListNode* temp = Top;
        Top = Top->next;

        printf("%d\n", temp->data);
        free(temp);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    pop();
    pop();
    pop();
    pop();
    pop();

}

