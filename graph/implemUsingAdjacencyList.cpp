// implementation of a graph using adjacency list
#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;
    void addedge(int u,int v,int direction){
        // direction =0 -> undirected
        // direction =1 -> directed

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<< i.first <<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
// if in place of map, we have to use vector
vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> &edges,int direction){
    vector<int> ans[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
      
        ans[u].push_back(v);
        if(direction==0){
            ans[v].push_back(u);
        }
    }
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            adj[i].push_back(i);
            for(int j=0;j<ans[i].size();j++){
                adj[j].push_back(ans[i][j]);
            }
        }
    return adj;
}
int main(){
    int n;
    cout<<"enter the no. of nodes: ";
    cin>>n;
    int m;
    cout<<"enter the no. of edges: ";
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addedge(u,v,0);
    }
    //printing graph
    g.printAdjList();
}