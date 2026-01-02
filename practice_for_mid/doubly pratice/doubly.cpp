#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode ListNode;


ListNode *createListNode(int user_data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = user_data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
ListNode* insertatpos(ListNode* head,int data,int pos){
    ListNode* newnode=createListNode(data);

if(head==NULL){
  head=newnode;
  head->next=NULL;
  head->prev=NULL;
  return head;

}
if(pos==1){
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
    return head;
}
else{
    ListNode* temp=head;
    int cnt=1;

    while(cnt<pos-1 && temp->next!=NULL){
          

        temp=temp->next;
        cnt++;
    }
    newnode->next=temp->next;
    if(temp->next != NULL)
       { temp->next->prev = newnode;}
    
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}
}

void deleteany(ListNode* head, int data){
    if(head==NULL){
        return;
    }
    else if(head->data==data){
        ListNode* temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
        return;
    }
    else{
        ListNode* i=head;
        while(i->next !=NULL && i->next->data !=data){
            i=i->next;
        }
        if(i->next==NULL)//data absent
        {
            return;
        }
        ListNode* temp=i->next;
        i->next=temp->next;
        temp->next->prev=i;
        free(temp);
        return;
    }
}

void printList(ListNode* head)
{

    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");


}
int main(){

ListNode* head=createListNode(5);
head=insertatpos(head,30,2);
printList(head);


}