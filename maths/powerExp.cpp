#include<iostream>
using namespace std;
int main(){
    int num,power,ans=1;
    cout<<"enter number:";
    cin>>num;
    cout<<"enter its power:";
    cin>>power;
    /*for(int i=1;i<=power;i++){
        ans=ans*num;
    }*/
   // time comp O(log n)
   int pow=power;
   power=abs(power);
   while(power>0){
    if(power%2!=0){
        ans=ans*num;
        power=power-1;
    }
    else{
        num=num*num;
        power=power/2;
    }
   }
   if(pow<0){
    cout<<1.0/ans<<endl;
   }
   else{
    cout<<ans<<endl;
   }
}