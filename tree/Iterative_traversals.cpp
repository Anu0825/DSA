#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> st;

    // start from root node (set current node to root node)
    Node* curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

vector<int> inorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> s;
    Node* current = root;

    while (current || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current) {
            s.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = s.top();
        s.pop();
        result.push_back(current->data);  // Visit the node

        // Move to the right subtree
        current = current->right;
    }

    return result;
}
vector<int> postOrderIterative(struct Node* root)
{
    vector<int> postOrderList;
    // Check for empty tree
    if (root == NULL)
        return postOrderList;
    stack<Node*> S;
    S.push(root);
    Node* prev = NULL;
    while (!S.empty()) {
        auto current = S.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == NULL || prev->left == current
            || prev->right == current) {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        }

        else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }

            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->right == prev) {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}
// Driver Code
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);

    preorderIterative(root);
    vector<int> ans=inorderTraversal(root);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}
