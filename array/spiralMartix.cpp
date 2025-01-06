// print the matrix in the spiral form
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"enter row nd colm:";
    cin>>n>>m;
    vector<int>ans;
    int arr[n][m];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>arr[i][j];
    } }
    int top=0,left=0;
    int right=m-1,bottom=n-1;
    while(left<=right && top<=bottom){
         for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
         }
         top++;
         for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
         }
         right--;
         if(top<=bottom){
         for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
         }
         bottom--;}
         if(left<=right){
         for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
         }
         left++;}
    }
    cout<<"the matrix in the spiral format is:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}