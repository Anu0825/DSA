// cycle detection in undirected (can be disconnected)graph using dfs traversal 
#include<bits/stdc++.h>
using namespace std;
bool IsCyclicDFS(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int node,int parent){
    visited[node]=true;

    // hr connected node ke liye recursive call
    for(auto i:adjList[node]){
        if(!visited[i]){
            bool cycleDetected=IsCyclicDFS(adjList,visited,i,node);
            if(cycleDetected){
                return true;
            }
            else if(i!=parent){
            return true;        
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
            bool ans=IsCyclicDFS(adjList,visited,i,-1);
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