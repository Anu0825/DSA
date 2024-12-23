#include<iostream>
#include<queue>
#include<map>
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
void solve(node* root,vector<int> & ans,int lvl){
    if(root==NULL){
        return;
    }
    if(ans.size()==lvl){
        ans.push_back(root->data);
    }
    solve(root->right,ans,lvl+1);
    solve(root->left,ans,lvl+1);
}
vector<int> left_view(node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}