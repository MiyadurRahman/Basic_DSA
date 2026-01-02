#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *createlistnode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node *inser(Node *head, int data)
{
    Node *newnode = createlistnode(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return head;
    }
    Node *temp=head;
    while(temp->next != NULL){
        temp=temp->next;

    }
    temp->next=newnode;
    return head;
}

Node *findmiddlenode(Node* head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    int mid = count / 2;

    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{Node* head=NULL;
    head = inser(head, 10);
    head=inser(head,20);
     head=inser(head,30); 
     head=inser(head,40);
    //   head=inser(head,50);
    //    head=inser(head,20);
    Node* middle=findmiddlenode(head);
    printf("%d",middle->data);
    
}