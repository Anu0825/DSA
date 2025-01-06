// doubt
#include<iostream>
#include<vector>
using namespace std;
bool issafe(int newx,int newy,vector<vector<bool>>&visited,vector<vector<int>>&arr,int n){
    if(arr[newx][newy]==1 && visited[newx][newy]!=1 && (newx>=0 && newx<n) && (newy>=0 && newy<n)){
        return true;
    }
    return false;
}
void solve(int x,int y,vector<vector<int>>&arr,int n,vector<string> &ans,vector<vector<bool>>&visited,string path){
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    // 4 movement [D,L,R,U]
    // down movement
    visited[x][y]=1;
    if(issafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,n,ans,visited,path+'D');
    }
    // left movement
    if(issafe(x,y-1,visited,arr,n)){
        solve(x,y-1,arr,n,ans,visited,path+'L');
    }
    // right movement
    if(issafe(x,y+1,visited,arr,n)){
        solve(x,y+1,arr,n,ans,visited,path+'R');
    }
    // up movement
    if(issafe(x-1,y,visited,arr,n)){
        solve(x-1,y,arr,n,ans,visited,path+'U');
    }
    visited[x][y]=0;
} 
vector<string> rateinMaze(vector<vector<int>>& arr,int n){
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}
int main(){
    int size;
    cout<<"enter size:";
    cin>>size;
    vector<vector<int>> arr;
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        vector<int> row;
        for(int j=0;j<size;j++){
            int value;
            cin>>value;
            row.push_back(value);
        }
        arr.push_back(row);
    }
    vector<string> ans=rateinMaze(arr,size);
    for(const auto& i:ans){
        cout<<i<<endl;
    }
}