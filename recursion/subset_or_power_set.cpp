#include<iostream>
#include<vector>
using namespace std;
void subset(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
if(index>=nums.size()){
     ans.push_back(output);
    return;}
subset(nums,output,index+1,ans);
int element=nums[index];
output.push_back(element);
subset(nums,output,index+1,ans);
}
int main(){
vector<int> nums,output;
vector<vector<int> > ans;
int elem,n;
cin>>n;
for(int i=0;i<n;i++){
    cout<<"enter an element:"<<endl;
    cin>>elem;
    nums.push_back(elem);
}
int index=0;
subset(nums,output,index,ans);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}}