/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly
 connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.*/





/*void dfs(int node,vector<int> adjList[],vector<int> &vis){
        vis[node]=1;
        for(auto i:adjList[node]){
            if(!vis[i]){
                dfs(i,adjList,vis);
            }
        }
    }
int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adjList[V];
        int cnt=0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjList,vis);
            }
        }
        return cnt;
    }
    */