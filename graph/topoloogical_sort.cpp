#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>> &adj,stack<int> &st){
    visited[node]=true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
        st.push(node);
    }
}
vector<int> DFS(int vertex,int m,vector<pair<int,int>>&edges){
    // prepare adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
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
    vector<int> ans=DFS(vertex,m,edges);
    for(auto i:ans){
        cout<<i<<" ";
    }
}