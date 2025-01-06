#include<iostream>
using namespace std;
void say_digit(int n,string arr[]){
if (n==0)
    return;
say_digit(n/10,arr);
cout<<arr[(n%10)]<<" ";
}
int main(){
int n;
cin>>n;
string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
say_digit(n,arr);
}