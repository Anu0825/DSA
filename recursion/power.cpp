#include<iostream>
using namespace std;
int power(int a,int b){
if (b==0)
    return 1;
return a*power(a,b-1);
}
int main(){
int a,b;
cout<<"enter no.:";
cin>>a;
cout<<"enter power:";
cin>>b;
cout<<"power is:"<<power(a,b)<<endl;
}