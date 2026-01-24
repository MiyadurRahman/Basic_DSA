#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
};

typedef struct TreeNode TreeNode;


void printTree(struct TreeNode *root, int level=0) {
    if (root == NULL)
        return;

    // Print right subtree first (so it appears on top)
    printTree(root->right, level + 1);

    // Print current node with indentation
    for (int i = 0; i < level; i++)
        printf("    ");

    printf("%d\n", root->data);

    // Print left subtree
    printTree(root->left, level + 1);
}

TreeNode* createTreeNode(int data)
{
    TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}


void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



TreeNode* insertion(TreeNode* root, int data, TreeNode* parent=NULL)
{
    if(root==NULL)
    {
        root = createTreeNode(data);
        root->parent = parent;
        return root;
    }
    else if(data > root->data)
    {
        root->right = insertion(root->right, data, root);
    }
    else
    {
        root->left = insertion(root->left, data, root);
    }
    return root;
}


TreeNode* searching(TreeNode* root, int key)
{
    if(root==NULL)
        return NULL;
    else if(root->data == key) return root;
    else if(key > root->data) return searching(root->right, key);
    else return searching(root->left, key);
}

TreeNode* deletion(TreeNode* root, int key)
{
    TreeNode* parent = NULL;
    TreeNode* temp = root;

    bool left = false;

    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            break;
        }
        if(key>temp->data)
        {
            parent = temp;
            temp = temp->right;
            left = false;
        }
        else
        {
            parent = temp;
            temp = temp->left;
            left = true;
        }
    }

    if(temp==NULL)
        return root;



    /// case 1: No child
    if(temp->left == NULL && temp->right == NULL)
    {
        free(temp);
        if(left==true)
            {
                if(parent!=NULL) {
                    parent->left = NULL;
                }
            }
        else
            {
                if(parent!=NULL)
                {
                    parent->right = NULL;
                }
            }
        return root;
    } /// case 2: One child
    else if(temp->left!=NULL && temp->right==NULL)
    {
        if(left==true)
        {
            if(parent) parent->left = temp->left;
            if(temp->left) temp->left->parent = parent;
            free(temp);
        }
        else
        {
            if(parent) parent->right = temp->left;
            if(temp->left) temp->left->parent = parent;
            free(temp);
        }
        return root;

    } else if(temp->left==NULL && temp->right!=NULL)
    {
        if(left==true)
        {
            if(parent) parent->left = temp->right;
            if(temp->right) temp->right->parent = parent;
            free(temp);
        }
        else
        {
            if(parent) parent->right = temp->right;
            if(temp->right) temp->right->parent = parent;
            free(temp);
        }
        return root;
    } /// case 2: Two child
    else
    {
        /// replacing with predecessor
        TreeNode* replacing_node = temp->left;

        while(replacing_node->right!=NULL)
        {
            replacing_node = replacing_node->right;
        }

        temp->data = replacing_node->data;
        temp->left = deletion(temp->left, replacing_node->data);

        return root;
    }




}

int main()
{


    int data[10] = {18, 15, 16, 20, 19, 25, 23, 5, 8, 10};
    TreeNode* root = NULL;
    for(int i=0; i<10; i++)
    {
        root = insertion(root, data[i]);
    }

    root = deletion(root, 20);

    printTree(root);
    return 0;
}