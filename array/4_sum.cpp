#include<bits/stdc++.h>
using namespace std;
void Four_Sum(int n,vector<int> &num,int sum){
       cout<<"solutions are:"<<endl;
       for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
               for(int k=(j+1);k<n;k++){
                 for(int l=(k+1);l<n;l++){
                  if ((num[i]+num[j]+num[k]+num[l])==sum){
                    cout<<num[i]<<" "<<num[j]<<" "<<num[k]<<" "<<num[l]<<endl;
        }}
    }
}}
}
// better approach
vector<vector<int>> FourSum(int n,vector<int> &num,int sum=0){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int tempsum=(num[i]+num[j]+num[k]);
                int fourth=(sum-tempsum);
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp={num[i],num[j],num[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
            }
            hashset.insert(num[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
int main(){
    int n,sum;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter sum:";
    cin>>sum;
    vector<int> num;
    num.resize(n);
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
         cin>>num[i];
    }
    Four_Sum(n,num,sum);
    vector<vector<int>> res;
    
}