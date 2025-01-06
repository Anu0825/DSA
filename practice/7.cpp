// remove duplicates elements
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n=8;
    vector<int> arr={1,1,2,2,2,3,4,5};
    /*set<int> ans;
    for(int i=0;i<8;i++){
    ans.insert(arr[i]);
    }
    for(auto i:ans){
        cout<<i<<" "; 
    }*/
    int start=0,end=1;
    while(start<n && end<n){
        if(arr[start]==arr[end]){
            int i=end;
            while(i<arr.size()-1){
                arr[i]=arr[i+1];
                i++;
            }
        }
        else{
            start++;
            end=start+1;
        }
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
}