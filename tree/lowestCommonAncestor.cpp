#include<iostream>
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
node* LCA(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftAns=LCA(root->left,n1,n2);
    node* rightAns=LCA(root->right,n1,n2);
    if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    else{
        return NULL;
    }
}