#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main(){
    int arr[10]={1,2,2,3,3,4,4,4,4,4};
    unordered_map<int,int> elementcount;
    for(int i:arr){
        elementcount[i]++;
    }
    bool ans=true;
    unordered_set<int> countSet;
    for (const auto& pair : elementcount) {
    if (!countSet.insert(pair.second).second) {
        ans=false; // Found a duplicate count
    }
}
cout<<ans<<endl;
}
