#include<iostream>
using namespace std;
bool IsPrime(int num){
    int cnt=0;
   for(int i=1;i*i<=num;i++){
    if(num%i==0){
         cnt++;
         if(num/i!=i){
            cnt++;
         }
         if(cnt>2){
            return false;
         }
    }
   }
   return true;
}
int main(){
    int num;
    cout<<"enter number:";
    cin>>num;
    //1. time comp -> O(n*sqrt(n))
    /*for(int i=2;i<=num;i++){
        if(num%i==0){
            if(IsPrime(i)){
                cout<<i<<" ";
            }
        }
    }*/
    //2. time comp -> O(sqrt(n)*2*sqrt(n))
    /*for(int i=2;i*i<=num;i++){
        if(num%i==0){
            if(IsPrime(i)){
                cout<<i<<" ";
            }
            if(num/i!=i && IsPrime(num/i)){
                cout<<num/i<<" ";
            }
        }
    }*/
   //3. time comp -> O(n)
    int i=2;
    while(num>1){
        if(num%i==0){
           cout<<i<<" ";
           while(num%i==0){
           num=num/i; }
        }
        i++;
    }
}