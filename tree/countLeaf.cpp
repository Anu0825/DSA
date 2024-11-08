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
void countLeaf(Node* node,int &count){
    //base case
    if(node==NULL){
        return;
    }
    countLeaf(node -> left,count);
    // leaf node
    if(node ->left ==NULL && node -> right==NULL){
        count++;
    }
    countLeaf(node -> right,count);
}