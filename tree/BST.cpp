#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    // Insert a node in the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Delete a node from the BST
    void deleteNode(int value) {
        root = deleteRecursive(root, value);
    }

    // Search for a value in the BST
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Inorder traversal to print BST elements
    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }

private:
    // Helper function to recursively insert a node
    Node* insertRecursive(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else if (value > node->data)
            node->right = insertRecursive(node->right, value);
        return node;
    }

    // Helper function to recursively delete a node
    Node* deleteRecursive(Node* node, int value) {
        if (!node) return node;

        // Find the node to delete
        if (value < node->data)
            node->left = deleteRecursive(node->left, value);
        else if (value > node->data)
            node->right = deleteRecursive(node->right, value);
        else {
            // Node with only one child or no child
            if (!node->left)
                return node->right;
            else if (!node->right)
                return node->left;

            // Node with two children: get the inorder successor
            node->data = minValue(node->right);

            // Delete the inorder successor
            node->right = deleteRecursive(node->right, node->data);
        }
        return node;
    }

    // Helper function to search recursively
    bool searchRecursive(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data)
            return searchRecursive(node->left, value);
        return searchRecursive(node->right, value);
    }

    // Helper function to find the minimum value node
    int minValue(Node* node) {
        int minVal = node->data;
        while (node->left) {
            node = node->left;
            minVal = node->data;
        }
        return minVal;
    }

    // Helper function for inorder traversal
    void inorderRecursive(Node* node) {
        if (node) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Deleting 20\n";
    bst.deleteNode(20);
    cout << "Inorder traversal after deletion: ";
    bst.inorder();

    cout << "Searching for 60: " << (bst.search(60) ? "Found\n" : "Not Found\n");
    cout << "Searching for 25: " << (bst.search(25) ? "Found\n" : "Not Found\n");

    return 0;
}
