//we have given a matrix. we have to make that row and columns all elem. zero at which zero is present.
// eg. [1 1 1 1]            [1 0 0 1]
//     [1 0 1 1]  -> ans =  [0 0 0 0]
//     [1 1 0 1]            [0 0 0 0]
//     [1 0 0 1]            [0 0 0 0]
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"enter row nd colm:";
    cin>>n>>m;
    vector<int>rows;
    vector<int>cols;
    int arr[n][m];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>arr[i][j];
    } }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }
    for(int i=0;i<rows.size();i++){
        for(int j=0;j<m;j++){
            arr[rows[i]][j]=0;
        }
    }
    for(int i=0;i<cols.size();i++){
        for(int j=0;j<n;j++){
            arr[j][cols[i]]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cout<<arr[i][j]<<" ";
    } 
    cout<<endl;
    }
}
