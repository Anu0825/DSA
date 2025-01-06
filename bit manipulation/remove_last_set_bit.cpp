//convert the last set bit to zero
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    n=n&(n-1);
    cout<<n<<endl;
}
// observation:
// num n eg. -> 40 -> 101000
// in num n-1 eg. -> 40-1=39 -> 100111
// the lst set bit is 0 and everything on right after set bit is 1 and all other are sme
// eg. 16 -> 10000 nd 15 -> 01111
