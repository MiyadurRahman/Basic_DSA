#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
struct Node* next;
};
typedef struct Node Node;
Node* createlistnode(int data){
Node* temp=(Node*)malloc(sizeof(Node));
temp->data=data;
temp->next=NULL;
return temp;

}
Node* head=NULL;
Node* tail=NULL;

Node* insert(Node* head,int data){
    Node*newnode=createlistnode(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return head;
    }
    tail->next=newnode;
    tail=newnode;
    return head;


}
void printlist(Node* head){
    for (Node* i=head;i!=NULL;i=i->next){
        printf("%d ",i->data);
    }

}

Node* insertsorted(Node*head,int data){
    Node* newnode=createlistnode(data);
    if(head==NULL || data<head->data){
        newnode->next=head;
        head=newnode;
        return head;
    }
    Node* temp=head;
    while (temp->next !=NULL && temp->next->data<data){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    if(newnode->next ==NULL){
tail=newnode;
    }
    return head;
}
void DeleteMin(){
    if(head == NULL)
        return;

    Node* current = head;
    Node* smallest = head;

    while(current != NULL){
        if(current->data < smallest->data)
          { smallest = current;}
        current = current->next;
    }

    // swap data with head
    int temp = head->data;
    head->data = smallest->data;
    smallest->data = temp;

    // delete head
    Node* del = head;
    head = head->next;
    if(head == NULL)
        tail = NULL;

    free(del);
}









int main(){
//  head=createlistnode(1);
tail=head;
head=insert(head,45);
head=insert(head,12);
head=insert(head,3);
head=insert(head,6);
head=insert(head,7);
printlist(head);
printf("\n");
insertsorted(head,20);
printlist(head);
printf("\n");
// printf("%d",tail->data);
 DeleteMin();   
 printf("\n");
 printlist(head) ;
}