// BFS(breadth first traversal) of a graph is an algorithm used to visit all of the nodes of a given graph.
// In this traversal algo, one node is selected then all of its adjacent nodes visited one by one
// you are given undirected nd disconnected grph. print its bfs traversal
#include<bits/stdc++.h>
using namespace std;
void prepAdjList(unordered_map<int,list<int>> &adjList,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int>&ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        // store front node into ans
        ans.push_back(frontNode);
        // traverse all the neighbours of frontNode
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex,vector<pair<int,int>>&edges){
    unordered_map<int,list<int>> adjList;   // to convert answer in sorted order just replace list by set
    vector<int>ans;
    unordered_map<int,bool> visited;
    prepAdjList(adjList,edges);
    // traverse all components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
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
    vector<int> ans=BFS(vertex,edges);
    for(auto i:ans){
        cout<<i<<" ";
    }
}