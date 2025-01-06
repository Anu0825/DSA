#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter n:";
cin>>n;
int num1[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin>>num1[i];
}
int num2[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin>>num2[i];
}
cout<<"common elements are:"<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if (num1[i]==num2[j]){
            cout<<num1[i]<<" ";
        }
    }
}}