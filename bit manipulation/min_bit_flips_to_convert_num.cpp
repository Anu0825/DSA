// find the min. no. of bit flips to convert a num into given num
// eg. 4 -> 100 nd 3 -> 011 all bits are diff. so we have to flip all three bits
#include<iostream>
using namespace std;
int main(){
    int num1,num2,n;
    cout<<"enter numbers:";
    cin>>num1>>num2;
    n=num1^num2;
    int cnt=0;
    while(n!=0){
        cnt+=(n&1);
        n=n>>1;
    }
    cout<<"min. no. of bits to flip: "<<cnt<<endl;
}