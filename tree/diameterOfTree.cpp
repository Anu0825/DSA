//maximum distance(width) between any two nodes
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
int diameterOfTree(struct Node* node){
    if(node==NULL){
        return 0;
    }
    int op1=diameterOfTree(node -> left);
    int op2=diameterOfTree(node -> right);
    int op3=heightOfTree(node -> left)+heightOfTree(node -> right)+1;
    int ans=max(op1,max(op2,op3));
    return ans;
}
// optimised approach
// first int -> diameter nd second int -> height
pair<int,int> diameter_fast(struct Node* node){
    if(node==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameter_fast(node -> left);
    pair<int,int> right=diameter_fast(node -> right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameter(struct Node* node){
    return diameter_fast(node).first;
}