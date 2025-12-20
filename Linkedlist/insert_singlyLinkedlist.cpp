#include <iostream>
using namespace std;
struct node{
int data;
node* next;

};
void inseratend(node* &head,int data){
    node* newnode=new node();
    newnode->data=data;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;

    }
    else{
        for(node* ptr=head;ptr!=NULL;ptr=ptr->next){
            if(ptr->next==NULL){//last node
                ptr->next=newnode;//linking last node to new node
                newnode->next=NULL;//ending the linked list 
                return;
            }
        
    }

}
}
//another way to insert using tail pointer
void insertatend_tail(node* &tail,int data){
    node* newnode=new node();
    newnode->data=data;
    tail->next=newnode;
    newnode->next=NULL;
    tail=newnode;//updating the tail pointer
}
void insertatbeginning(node* &head,int data){//reference of head pointer.why reference? because we want to change the head pointer
    //new node creation
    node* newnode=new node();
    newnode->data=data;
    newnode->next=head;//linking new node to previous head
    head=newnode;
}
void printlinkedlist(node* head){
    for(node* ptr=head;ptr!=NULL;ptr=ptr->next){
        cout<<ptr->data<<" ";
    }
}
int main(){
    node* head;
    node* second;
    node* third;
    
    head=new node();
    second=new node();
    third=new node();
    node* tail=third;//initially tail is pointing to last node
    head->data=1;
    head->next=second;//linking first node to second
    second->data=2;
    second->next=third;//linking second node to third
    third->data=3;

    third->next=NULL;//ending the linked list
    //printing the linked list
    // node* ptr=head;//why head? because head contains the address of first node
    // // while(ptr!=NULL){//why condition ptr!=NULL? because when ptr becomes NULL, we have reached the end of linked list.how?
    // //     cout<<ptr->data<<" ";
    // //     ptr=ptr->next;//updating the pointer to next node
    // // }

    
    // for(node* ptr=head;ptr!=NULL;ptr=ptr->next){
    //     cout<<ptr->data<<" ";
    // }

    printlinkedlist(head); 
    insertatbeginning(head,12);
    cout<<endl;
    printlinkedlist(head);
    
    insertatend_tail(tail,15);
    cout<<endl;
    printlinkedlist(head);
    return 0;
}   
