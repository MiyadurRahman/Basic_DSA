#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    ListNode* next;
};

ListNode* Front = NULL;
ListNode* Rear = NULL;

ListNode* createListNode(int data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(int data)
{
    if(Front==NULL)
    {
        Front = createListNode(data);
        Rear = Front;
    }
    else
    {
        ListNode* temp = createListNode(data);
        Rear->next = temp;
        Rear = Rear->next;
    }
}


void dequeue()
{
    if(Front==NULL)
    {
        printf("Queue Underflow\n");
    }
    else if(Front==Rear)
    {
        printf("%d\n", Front->data);
        free(Front);
        Front = Rear = NULL;
    }
    else
    {
        ListNode* temp = Front;
        Front = Front->next;

        printf("%d\n", temp->data);
        free(temp);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
}
