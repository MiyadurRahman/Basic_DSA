#include <stdio.h>
#include <stdlib.h>


struct DBTNode {
int value;
struct DBTNode* left;
struct DBTNode* right;
};
typedef struct DBTNode DBTNode;
DBTNode* createDBTNode(int data){
    DBTNode* temp=(DBTNode*)malloc(sizeof(DBTNode));
    temp->value=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
DBTNode* insertDBT(DBTNode* root,int value){
    if(root==NULL){

      
        return createDBTNode(value);
    }
    if(value % root->value==0){
        root->left=insertDBT(root->left,value);
    }
    else{
        root->right=insertDBT(root->right,value);
    }
return root;


}
int countDisivibler(DBTNode* root,int divisor){
    int count=0;
    if(root==NULL){
        return 0;
    }
    if(root->value % divisor==0){
        count++;
    }
    count=count+countDisivibler(root->left,divisor);
    count=count+countDisivibler(root->right,divisor);
    return count;
}
int countNodes(DBTNode* root, int target) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left, target) + countNodes(root->right, target);
}
void printPathToNode(DBTNode* root,int target){
   if(root=NULL){
    printf("not found");
    return;
   }
   DBTNode* temp=root;
   while(temp!=NULL){
    printf("%d",temp->value);
    if(temp->value==target){
        return;

    }
    printf("->");
    if(target % temp->value ==0){
        temp=temp->left;
    }
    else{
        temp=temp->right;
    }
printf("not found");
   }
   
}
int main() {
   DBTNode* root=NULL;
   root=insertDBT(root,3);
   root=insertDBT(root,4);
   root=insertDBT(root,2);
    root=insertDBT(root,9);
   root=insertDBT(root,6);
   int target;
printf("enter target: ");
   scanf("%d",&target);
   printPathToNode(root,target);

    return 0;
}