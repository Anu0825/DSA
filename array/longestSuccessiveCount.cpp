#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int longestSuccessiveElem(vector<int> &arr){
    int n=arr.size();
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto i:st){
        if(st.find(i-1) == st.end()){
            int cnt=1;
            int x=i;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}
int main(){
    vector<int> arr={100,102,101,1,1,3,4,2,5,2};    //-> ans={1,2,3,4,5} -> 5
    cout<<longestSuccessiveElem(arr)<<endl;
}
