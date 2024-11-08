// a tree is balanced if difference btw height of left nd right subtrees is not more than one for all nodes
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
int heightOfTree(struct Node* node){
    if(node==NULL){
        return 0;
    }
    int left=heightOfTree(node -> left);
    int right=heightOfTree(node -> right);
    int ans=max(left,right)+1;
    return ans;
}
// time comp -> O(n^2)
bool isBalanced(struct Node* root){
    // base case
    if(root == NULL){
        return true;
    }
    bool left=isBalanced(root -> left);
    bool right=isBalanced(root -> right);
    bool diff= abs(heightOfTree(root->left) - heightOfTree(root-> right))<=1;
    if(left && right && diff){
        return true;
    }
    else
        return false;
}
// time comp -> O(n)
// in this approach we will make pair, bool store value for balanced nd int stores height
pair<bool,int> isBalanced_fast(struct Node* root){
    // base case
    if(root == NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<int,int> left=isBalanced_fast(root-> left);
    pair<int,int> right=isBalanced_fast(root-> right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff= abs(left.second - right.second)<=1;
    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+ 1;
    if(leftAns && rightAns && diff){
        ans.first=true;
    }
    else
        ans.first=false;
    return ans;
}
bool is_balanced(struct Node* root){
    return isBalanced_fast(root).first;
}