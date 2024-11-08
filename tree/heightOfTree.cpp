// find the height of the tree
// height is the longest path between root node nd leaf note
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
int main(){
}
