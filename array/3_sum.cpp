#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(int n,vector<int> &num,int sum=0){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third=-(num[i]+num[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={num[i],num[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
vector<vector<int>> tripletUsePointers(int n,vector<int> &num,int sum=0){
    vector<vector<int>> ans;              // TC:O(n^2)
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++){
        if(i>0 && num[i]==num[i-1])
        continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=num[i]+num[j]+num[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp={num[i],num[j],num[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && num[j]==num[j-1]) j++;
                while(j<k && num[k]==num[k+1]) k--;
            }
        }
    }
    return ans;
}
void tripletSum(int n,vector<int> &num,int sum){
       cout<<"the triplets are:"<<endl;
       for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
               for(int k=(j+1);k<n;k++){
                  if ((num[i]+num[j]+num[k])==sum){
                    cout<<num[i]<<" "<<num[j]<<" "<<num[k]<<endl;
        }
    }
}}
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
tripletSum(n,num,sum);
vector<vector<int>> ans=triplet(n,num);
cout<<"triplets are:"<<endl;
for(const auto &row:ans){
    for(const auto &elem:row){
        cout<<elem<<" ";
    }
    cout<<endl;
}
vector<vector<int>> res=tripletUsePointers(n,num);
cout<<"triplets are:"<<endl;
for(const auto &row:res){
    for(const auto &elem:row){
        cout<<elem<<" ";
    }
    cout<<endl;
}
}
