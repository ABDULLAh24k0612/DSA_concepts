#include <iostream>
#include <queue>  
using namespace std;


struct Node {
    int data;       
    Node* left;     
    Node* right;   

    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class BST {
private:
    Node* root;  

 
    Node* insert(Node* node, int val) {
        
        if (node == nullptr) {
            return new Node(val);
        }

        
        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        

        return node;
    }

    
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val) {
            return node;
        }

        if (val < node->data) {
            return search(node->left, val);
        }
        else {
            return search(node->right, val);
        }
    }

    
    Node* findMin(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        else if(node->left==nullptr){
            return node;
        }
        else{
            return findMin(node->left);
        }
    }

    
    Node* findMax(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        else if(node->right==nullptr){
            return node;
        }
        else{
            return findMax(node->right);
        }
    }

    
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        }
        else {
            // Found the node to delete

            // Case 1: No left child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Case 2: No right child
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            else {
                // Find the inorder successor (smallest in right subtree)
                Node* temp = findMin(node->right);

                // Replace node’s value with successor’s value
                node->data = temp->data;

                // Delete the successor
                node->right = deleteNode(node->right, temp->data);
            }
        }

        return node;
    }

    // ----------------------------------------------------------
    // Recursive Traversal Functions
    // ----------------------------------------------------------
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // ----------------------------------------------------------
    // Find the height of the BST recursively
    // ----------------------------------------------------------
    int height(Node* node) {
        if (node == nullptr) {
            return -1;  // Height of an empty tree = -1
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }

    // ----------------------------------------------------------
    // Find the predecessor (largest smaller value)
    // ----------------------------------------------------------
    Node* findPredecessor(Node* node, int val) {
        Node* current = search(root, val);
        if (current == nullptr) {
            return nullptr;
        }

        // Case 1: Node has a left subtree
        if (current->left != nullptr) {
            return findMax(current->left);
        }

        // Case 2: No left subtree → find nearest ancestor smaller than current
        Node* predecessor = nullptr;
        Node* ancestor = root;

        while (ancestor != current) {
            if (val > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else {
                ancestor = ancestor->left;
            }
        }

        return predecessor;
    }

    // ----------------------------------------------------------
    // Find the successor (smallest greater value)
    // ----------------------------------------------------------
    Node* findSuccessor(Node* node, int val) {
        Node* current = search(root, val);
        if (current == nullptr) {
            return nullptr;
        }

        // Case 1: Node has a right subtree
        if (current->right != nullptr) {
            return findMin(current->right);
        }

        // Case 2: No right subtree → find nearest ancestor larger than current
        Node* successor = nullptr;
        Node* ancestor = root;

        while (ancestor != current) {
            if (val < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }

        return successor;
    }

public:
    // Constructor initializes empty tree
    BST() {
        root = nullptr;
    }

    // ================================================================
    // Public methods (Wrappers that call private recursive functions)
    // ================================================================

    void insert(int val) {
        root = insert(root, val);
    }

    void update(int oldVal, int newVal) {
        Node* found = search(root, oldVal);
        if (found != nullptr) {
            root = deleteNode(root, oldVal);
            root = insert(root, newVal);
            cout << "Updated " << oldVal << " → " << newVal << endl;
        }
        else {
            cout << "Value " << oldVal << " not found for update!" << endl;
        }
    }

    void searchValue(int val) {
        Node* result = search(root, val);
        if (result != nullptr) {
            cout << val << " found in the BST." << endl;
        }
        else {
            cout << val << " not found in the BST." << endl;
        }
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    // ---------------- Traversals ----------------
    void inorder() {
        cout << "In-order: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Pre-order: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Post-order: ";
        postorder(root);
        cout << endl;
    }

    // ----------------------------------------------------------
    // Breadth-First Traversal (Level Order)
    // ----------------------------------------------------------
    void BFT() {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "Breadth-First Traversal (Level Order): ";

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }

    // ----------------------------------------------------------
    // DFS (Depth-First Traversal)
    // Here we’ll just print Inorder as one form of DFS
    // ----------------------------------------------------------
    void DFS() {
        cout << "Depth-First Traversal (In-order): ";
        inorder(root);
        cout << endl;
    }

    // ----------------------------------------------------------
    // Find minimum and maximum value in BST
    // ----------------------------------------------------------
    void findMin() {
        Node* node = findMin(root);
        if (node != nullptr) {
            cout << "Minimum value: " << node->data << endl;
        }
        else {
            cout << "Tree is empty." << endl;
        }
    }

    void findMax() {
        Node* node = findMax(root);
        if (node != nullptr) {
            cout << "Maximum value: " << node->data << endl;
        }
        else {
            cout << "Tree is empty." << endl;
        }
    }

    // ----------------------------------------------------------
    // Find predecessor and successor
    // ----------------------------------------------------------
    void findPredecessor(int val) {
        Node* pred = findPredecessor(root, val);
        if (pred != nullptr) {
            cout << "Predecessor of " << val << " is " << pred->data << endl;
        }
        else {
            cout << "No predecessor found for " << val << endl;
        }
    }

    void findSuccessor(int val) {
        Node* succ = findSuccessor(root, val);
        if (succ != nullptr) {
            cout << "Successor of " << val << " is " << succ->data << endl;
        }
        else {
            cout << "No successor found for " << val << endl;
        }
    }

    // ----------------------------------------------------------
    // Find the height of the tree
    // ----------------------------------------------------------
    void findHeight() {
        cout << "Height of the tree: " << height(root) << endl;
    }
};

// ======================================================================
//  Main Function (Driver Code to Demonstrate Operations)
// ======================================================================
int main() {
    BST bst;

    // Insert sample data
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display different traversals
    bst.inorder();
    bst.preorder();
    bst.postorder();
    bst.BFT();
    bst.DFS();

    // Search values
    bst.searchValue(40);
    bst.searchValue(100);

    // Min, Max, Height
    bst.findMin();
    bst.findMax();
    bst.findHeight();

    // Predecessor & Successor
    bst.findPredecessor(60);
    bst.findSuccessor(60);

    // Update a value
    cout << "\nUpdating 40 → 45" << endl;
    bst.update(40, 45);
    bst.inorder();

    // Delete a node
    cout << "\nDeleting 70" << endl;
    bst.deleteValue(70);
    bst.inorder();

    return 0;
}
