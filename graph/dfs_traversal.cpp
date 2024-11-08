#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>> &adj,vector<int> &component){
    component.push_back(node);
    visited[node]=true;

    // hr connected node ke liye recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}
vector<vector<int>> DFS(int vertex,int m,vector<pair<int,int>>&edges){
    // prepare adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main(){
    int vertex;
    cout<<"enter vertex:";
    cin>>vertex;
    int m;
    cout<<"enter no. of edges:";
    cin>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back(make_pair(u,v));
    }
    vector<vector<int>> ans=DFS(vertex,m,edges);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}