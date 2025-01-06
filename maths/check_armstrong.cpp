//number is a armstrong if its sum of cube of digits is equal to the number.
// eg. 371 -> 27+343+1=371
#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout<<"enter n:";
    cin>>n;
    int dup=n;
    while(n>0){
        int lastdig=n%10;
        n=n/10;
        sum=sum+(lastdig*lastdig*lastdig);
    }
    if(sum==dup){
        cout<<"given number is armstrong"<<endl;
    }
    else{
        cout<<"number is not a armstrong"<<endl;
    }
}