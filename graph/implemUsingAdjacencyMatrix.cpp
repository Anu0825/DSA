// implementation of graph using adjacency matrix
// time comp O(n^2) nd spc comp O(n^2)
#include<iostream>
using namespace std;
# define n 6
void addEdge(int adjMatrix[n][n],int u,int v,int direction){
    adjMatrix[u][v]=1;
    if(direction==0){
        adjMatrix[v][u]=1;}
}
void printAdjMatrix(int adjMatrix[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int adjMatrix[n][n];
    int m;
    cout<<"enter no. of edges:";
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adjMatrix[i][j]=0;
        } 
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // for undirected graph
        addEdge(adjMatrix,u,v,0);
    }
    cout<<"adjacency matrix:"<<endl;
    printAdjMatrix(adjMatrix);
}