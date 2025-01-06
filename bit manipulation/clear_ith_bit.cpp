//if ith bit is zero then reamin as it is if 1 convert to 0
#include<iostream>
using namespace std;
int main(){
    int n,bit;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter bit:";
    cin>>bit;
    n=n&(~(1<<bit));
    cout<<n<<endl;
}