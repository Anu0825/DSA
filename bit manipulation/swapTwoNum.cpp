#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter numbers: ";
    cin>>a>>b;
    //using 3rd var
    /*int temp;
    temp=a;
    a=b;
    b=temp;*/
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b<<endl;
}