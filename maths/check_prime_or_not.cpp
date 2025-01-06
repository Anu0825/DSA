#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter number:";
    cin>>num;
    bool isPrime=true;
    //time comp -> O(n)
    /*for(int i=2;i<num;i++){
        if(num%i==0){
            isPrime=false;
            break;
        }
    }
    if(!isPrime || num==1){
        cout<<"not a prime number"<<endl;
    }
    else{
        cout<<"prime number"<<endl;
    }*/
   //time comp -> O(sqrt(n))
   int cnt=0;
   for(int i=1;i*i<=num;i++){
    if(num%i==0){
         cnt++;
         if(num/i!=i){
            cnt++;
         }
         if(cnt>2){
            break;
         }
    }
   }
   if(cnt==2){
        cout<<"prime number"<<endl;
    }
    else{
        cout<<"not a prime number"<<endl;
    }
}