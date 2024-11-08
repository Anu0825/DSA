// cycle detection in undirected (can be disconnected)graph using bfs traversal 
#include<bits/stdc++.h>
using namespace std;
bool IsCyclicBFS(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int src){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        // traverse all the neighbours of frontNode
        for(auto i: adjList[frontNode]){
            if(visited[i]==true && i!=parent[frontNode]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i]=1;
                parent[i]=frontNode;
            }
        }
    }
    return false;
}
string cycleDetection(int vertex,vector<pair<int,int>>&edges){
    unordered_map<int,list<int>> adjList;  
    unordered_map<int,bool> visited;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // traverse all components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bool ans=IsCyclicBFS(adjList,visited,i);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
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
    cout<<"cycle is present -> "<<cycleDetection(vertex,edges)<<endl;
}