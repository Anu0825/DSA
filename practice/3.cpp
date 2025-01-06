//find the no. of 1 bits in a given no. 
//eg. 4 --> 100 , no. of 1 bits:1
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    int count=0;
    while(n>0){
        count=count+(n&1);
        n>>=1;                 //right shift
    }
    cout<<count<<endl;
}                         