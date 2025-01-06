#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size:";
    cin>>n;
    int arr[n][n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int min_row_elem=arr[i][0];
        int min_col_elem=arr[0][i];
        for(int j=0;j<n;j++){
            if(i!=0){
            if(arr[i][j]<arr[i][j-1]){
                min_row_elem=arr[i][j];
            }
            }
            if(j!=0){
            if(arr[j][i]<arr[j][i-1]){
                min_col_elem=arr[j][i];
            }
            }
        }
        cout<<"min elem for "<<i+1<<" row :"<<min_row_elem<<endl;
        cout<<"min elem for "<<i+1<<" col :"<<min_col_elem<<endl;
    }
}