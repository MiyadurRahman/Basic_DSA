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

void printPathToNode(DBTNode* root,int target){
   if(root==NULL){
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

   }
   printf("not found");
   
}
int findextreme(DBTNode* root,int findmax){
    
    if(root==NULL){
        printf("tree empty");
        return -1;
    }
    if(findmax)
    {
        int maxvalue=root->value;
        if(root->right!=NULL){
            int rightmax=findextreme(root->right,findmax);
            if(rightmax>maxvalue){
                maxvalue=rightmax;
            }
        }
        if(root->left!=NULL){
            int leftmax=findextreme(root->left,findmax);
            if(leftmax>maxvalue){
                maxvalue=leftmax;
            }
        }
        return maxvalue;
    }
    else{ 
        int minvalue=root->value;
        if(root->left!=NULL){
            int leftmin=findextreme(root->left,findmax);
            if(leftmin<minvalue){
                minvalue=leftmin;
            }
        }
        if(root->right!=NULL){
            int rightmin=findextreme(root->right,findmax);
            if(rightmin<minvalue){
                minvalue=rightmin;
            }
        }
        return minvalue;
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
   printf("\n");
printf("%d\n",findextreme(root,1));
printf("%d\n",findextreme(root,0));

printf("%d",countDisivibler(root,3));

    return 0;
}