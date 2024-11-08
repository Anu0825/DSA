#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=3;
    int w=4;
    int profit[3]={1,2,3};
    int weight[3]={4,5,1};
    vector<int> wt;
    for(int i=0;i<n;i++){
        if(weight[i]>=w){
            wt.push_back(i);
        }
    }
    int prf=0,wgt=0,ans=0;
    for(auto i:wt){
        if(wgt<=w)
        {
           prf=prf+profit[i];
           wgt+=weight[i];
        }
        ans=max(prf,ans);
    }
    cout<<ans;
}