#include <iostream>
using namespace std;
struct node{
int data;
node* next;

};
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

    
    return 0;

}   
