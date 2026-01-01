#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
  struct   Node* next;
};
typedef struct Node Node;
Node* createlistnode(int data){
    Node* temp =(Node*)malloc(sizeof(Node));
      temp->data=data;
      temp->next=NULL;
      return temp;

}
Node* insertatpos(Node* head,int data,int position){
Node* newnode=createlistnode(data);
Node* temp=head;


if(position==-1){
    newnode->next=head;
    head=newnode;
    return head;
}
else{
int count=1;
while (count<position){
     temp=temp->next;
    count++;
}
if(temp->next==NULL){
    newnode->next=NULL;
    temp->next=newnode;
    return head;
}
newnode->next=temp->next;

temp->next=newnode;

return head;
}



}
Node* deleteatpos(Node* head,int position){
    if(head==NULL || position==-1){
        return head;

    }
    else if(position ==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    else{
        int count=1;
        Node* temp=head;
        Node* temp2;
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        temp2=temp->next;
        if(temp->next==NULL){
            return head;
        }
        temp->next=temp2->next;
        free(temp2);
        return head;
    }
}
void print_array(Node* head){
for(Node* temp=head;temp!=NULL;temp=temp->next){
    printf("%d ",temp->data);
}


}
int main(){
Node* head=createlistnode(5);
//printf("%d",head->data);
head=insertatpos(head,30,1);
print_array(head);
head=deleteatpos(head,1);
printf("\n");
print_array(head);



}