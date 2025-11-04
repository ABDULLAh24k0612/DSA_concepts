#include <iostream>
using namespace std;
class Node{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
        height = 0; 
    }
};
int height(Node *N)
{
    if (N == nullptr)
        return -1;
    return N->height;
}
int getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node *leftRotate(Node *y)
{
    Node *x = y->right;
    Node *T2 = y->left;
    x->left = y;
    y->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
Node *insert(Node *node, int key)
{
    if (node == nullptr)
    {
        Node *newNode = new Node(key); 
        return newNode;
    }
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* findmin(Node* root){
    Node* current=root;
    while(current&&current->left!=NULL){
        current=current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
         if(root->left==NULL){
                Node*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node*temp=root->left;
                delete root;
                return temp;
            }

            Node*temp=findmin(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
    }
    if (root == nullptr) 
        return root; 
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int key : keys)
    {
        root = insert(root, key);
    }
    cout << "AVL Tree created with root key: " << root->key << endl;
    return 0;
} 
