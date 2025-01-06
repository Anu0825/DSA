// given an array of integers nd generate all possible permutations of that array
// TC of both functions are O(n*n!)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void generateUsingBuiltIn(vector<int> & arr){
    sort(arr.begin(),arr.end());
    cout<<"all permutations are:"<<endl;     // to generate in lexicographical order
    do{
        for(int i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }while(next_permutation(arr.begin(),arr.end()));
}
void permutate(vector<int> &arr,int start,int end){
    if(start==end){
        for(int i=0;i<=end;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl; 
    }
    else{
        for(int i=start;i<=end;i++){
            swap(arr[start],arr[i]);
            permutate(arr,start+1,end);
            swap(arr[start],arr[i]);  //backtrack
        }
    }
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    generateUsingBuiltIn(arr);
    cout<<"all permutations are:"<<endl;
    permutate(arr,0,n-1);
}