#include<iostream>
#include<vector>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void leftTraversal(vector<int> &ans,node* root){
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return ;
    }
    ans.push_back(root->data);
    if(root->left)
         leftTraversal(ans,root->left);
    else
         leftTraversal(ans,root->right);
}
void traverseLeaf(vector<int> &ans,node* root){
    // base case
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(ans,root->left);
    traverseLeaf(ans,root->right);
}
void rightTraversal(vector<int> &ans,node* root){
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return ;
    }
    if(root->right)
         leftTraversal(ans,root->right);
    else
         leftTraversal(ans,root->left);
    ans.push_back(root->data);
}
vector<int> BoundaryTraversal(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    //left part print/store
    leftTraversal(ans,root->left);
    // traverse leaf noodes
    //left subtree
    traverseLeaf(ans,root->left);
    //right subtree
    traverseLeaf(ans,root->right);
    //right part print/store
    leftTraversal(ans,root->right);
    return ans;
}