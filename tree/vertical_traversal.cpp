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
vector<int> verticaltraversal(node* root){
    // first int for horizontal dist. in sec. map first int -> levels nd other vector store nodes
    map<int,map<int,vector<int>>> nodes;
    //2nd pair horiz. dist nd levels
    queue<pair<node*,pair<int,int>>> q;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    // for root node both horz. dist nd level=0
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int>> temp=q.front();
        q.pop();
        node* frontnode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(frontnode->data);
        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}