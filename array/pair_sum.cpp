#include<iostream>
using namespace std;
int main(){
int n,sum;
cout<<"enter n:";
cin>>n;
cout<<"enter sum:";
cin>>sum;
int num[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin>>num[i];
}
cout<<"the pairs are:"<<endl;
for(int i=0;i<n;i++){
    for(int j=(i+1);j<n;j++){
        if ((num[i]+num[j])==sum){
            cout<<num[i]<<" "<<num[j]<<endl;
        }
    }
}}