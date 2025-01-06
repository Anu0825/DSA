// rotation in the same matrix
#include<iostream>
using namespace std;
int main(){
    int row,col;
    cout<<"enter row and col:";
    cin>>row>>col;
    int arr[row][col];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
}   }
// first take the transpose of the matrix
    for(int i=0;i<row-1;i++){
        for(int j=i+1;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
// reverse each row in matrix
    for(int i=0;i<row;i++){
        int start=0,end=col-1;
        while(start<=end){
            swap(arr[i][start],arr[i][end]);
            start++;
            end--;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
}  cout<<endl;
 }
}