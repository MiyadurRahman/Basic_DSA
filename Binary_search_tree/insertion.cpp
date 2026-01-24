#include <iostream>
using namespace std;

struct treenode {
    char data;
    treenode* parent;
    treenode* left;
    treenode* right;
};

// Version 1: Return the updated root
treenode* insert(treenode* root, char data, treenode* parent = NULL) {
    if (root == NULL) {
        root = new treenode();
        root->data = data;
        root->parent = parent;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (data > root->data) {
        root->right = insert(root->right, data, root);
    }
    else {
        root->left = insert(root->left, data, root);
    }
    return root;
}

// Version 2: Using reference for root (better)
void insertRef(treenode*& root, char data, treenode* parent = NULL) {
    if (root == NULL) {
        root = new treenode();
        root->data = data;
        root->parent = parent;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    
    if (data > root->data) {
        insertRef(root->right, data, root);
    } else {
        insertRef(root->left, data, root);
    }
}

void printTree(treenode* root, int level = 0) {
    if (root == NULL)
        return;

    // Print right subtree first (so it appears on top)
    printTree(root->right, level + 1);

    // Print current node with indentation
    for (int i = 0; i < level; i++)
        cout << "    ";

    cout << root->data;
    
    // Print parent information if available
    if (root->parent != NULL) {
        cout << " (parent: " << root->parent->data << ")";
    }
    cout << endl;

    // Print left subtree
    printTree(root->left, level + 1);
}

// In-order traversal
void inorder(treenode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find a node in the tree
treenode* search(treenode* root, char data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data > root->data) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

int main() {
    // Method 1: Using return value (must capture it)
    cout << "=== Method 1: Using return value ===\n";
    treenode* root = NULL;
    root = insert(root, 'A');
    root = insert(root, 'C');
    root = insert(root, 'B');
    root = insert(root, 'E');
    root = insert(root, 'D');
    
    cout << "Tree structure:\n";
    printTree(root);
    
    cout << "\nIn-order traversal: ";
    inorder(root);
    cout << endl;
    
    // Method 2: Using reference (cleaner)
    cout << "\n=== Method 2: Using reference ===\n";
    treenode* root2 = NULL;
    insertRef(root2, 'M');
    insertRef(root2, 'G');
    insertRef(root2, 'T');
    insertRef(root2, 'B');
    insertRef(root2, 'K');
    insertRef(root2, 'Q');
    insertRef(root2, 'Z');
    
    cout << "Tree structure:\n";
    printTree(root2);
    
    cout << "\nIn-order traversal: ";
    inorder(root2);
    cout << endl;
    
    // Search example
    cout << "\n=== Search Example ===\n";
    char searchChar = 'K';
    treenode* found = search(root2, searchChar);
    if (found != NULL) {
        cout << "Found '" << searchChar << "' in the tree.\n";
        if (found->parent != NULL) {
            cout << "Its parent is: '" << found->parent->data << "'\n";
        }
    } else {
        cout << "'" << searchChar << "' not found in the tree.\n";
    }
    
    // Clean up memory (important!)
    // In a real program, you should add a deleteTree function
    // to recursively delete all nodes
    
    return 0;
}