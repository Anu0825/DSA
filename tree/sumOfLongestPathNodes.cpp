// find the sum of the nodes of longest path between root to leaf node
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
void solve(node* root,int sum,int &maxsum,int len,int &maxlen){
    // base case
    if(root==NULL){
        if(len > maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len == maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}
int sumOfNodes(node* root){
    int len=0;
    int maxlen=0;
    int sum=0;
    int maxsum=0;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}