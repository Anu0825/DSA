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
vector<int> top_view(node* root){
    // first int for horizontal dist.and sec. map store nodes
    map<int,int> topnode;
    //2nd horiz. dist
    queue<pair<node*,int>> q;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    // for root node horz. dist0
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* frontnode=temp.first;
        int hd=temp.second;
        if(topnode.find(hd) == topnode.end()){
            topnode[hd]=frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto i:topnode){
        ans.push_back(i.second);
    }
    return ans;
}