#include<iostream>
#include<vector>
using namespace std;
void subset(string str,string output,int index,vector<string>& ans){
if(index>=str.length()){
     ans.push_back(output);
    return;}
//exclude
subset(str,output,index+1,ans);
//include
int element=str[index];
output.push_back(element);
subset(str,output,index+1,ans);
}
int main(){
string output="";
vector<string > ans;
string str;
cout<<"enter string:"<<endl;
cin>>str;
int index=0;
subset(str,output,index,ans);
cout<<"subsequences of given string are:"<<endl;
for(string i:ans){
    cout<<i<<endl;
}
}