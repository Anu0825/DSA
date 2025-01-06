//we have to given an array nd we have to return all the superior(leader) elements ans then sort it.
//superior elements -> that elem is greater than its all rightmost elements
// eg. {10,22,12,3,0,6} -> ans={6,12,22}
#include<iostream>
#include<vector>
using namespace std;
void leaderElem(vector<int> &ans,int arr[],int size){
    int maxi=INT16_MIN;
    int ptr=size-1;
    while(ptr>=0){
        if(arr[ptr]>maxi){                       // ans is already sorted as we are placing elem only when
            ans.push_back(arr[ptr]);             // it is greater than maxi
        }                                        // optimal approach with time comp O(n)
        maxi=max(maxi,arr[ptr]);
        ptr--;
    }
}
void leaderElem2(vector<int> &ans,int arr[],int size){
    for(int i=0;i<size;i++){
        bool leader=true;
        for(int j=(i+1);j<size;j++){
            if(arr[j]>arr[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    int i=0,j=ans.size()-1;
    while(i<=j){
        swap(ans[i],ans[j]);
        i++,j--;
    }
}
int main(){
    int size;
    cout<<"enter size:";
    cin>>size;
    vector<int>ans;
    int *arr=new int[size];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    leaderElem(ans,arr,size);
    //leaderElem2(ans,arr,size);
    for(auto i:ans){
        cout<<i<<" ";
    }
}