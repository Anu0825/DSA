// return true if for every node in tree except leave node, its value is equal to sum of its left subtree
// values nd its right subtrees values,else return false
#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
pair<bool,int> isSumTree(struct Node* root){
    // base case
    if(root == NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;   
    }
    pair<bool,int> left=isSumTree(root-> left);
    pair<bool,int> right=isSumTree(root-> right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool sum= (left.second + right.second)==(root->data);
    pair<bool,int> ans;
    if(leftAns && rightAns && sum){
        ans.first=true;
        ans.second=left.second + right.second + root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}
bool isSumTree_fast(struct Node* node){
    return isSumTree(node).first;
}