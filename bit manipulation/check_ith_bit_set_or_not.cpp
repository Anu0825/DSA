//bit starting from last nd without conversion into binary
//check ith bit is 1 or not
#include<iostream>
using namespace std;
int main(){
    int n,bit;
    bool ans=false;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter bit:";
    cin>>bit;
    //using left shift
    /*if((n&(1<<bit))!=0){
        ans=true;
    }*/
    //using right shift
    if(((n>>bit)&1)!=0){
        ans=true;
    }
    cout<<ans<<endl;
}