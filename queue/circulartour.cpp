// important ques.
// suppose there is a circle. there are n petrol pumps on that circle. you will be given two sets of data.
// 1. the amount of petrol that evry petrol pump has.
// 2. distance from that petrol pump to the next petrol pump.
//find a starting point where the truck can start to get through complete circle without exhausting
// its petrol in between.
#include<iostream>
#include<queue>
using namespace std;
int circularTour(int petrol[],int distance[],int n){
    int deficit=0;
    int balance=0;
    int start=0;
    for(int i=0;i<n;i++){
        balance+=petrol[i]-distance[i];
        if(balance<0){
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(deficit+balance>=0){
        return start;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int *petrol=new int[n];
    int *distance=new int[n];
    cout<<"enter petrol:"<<endl;
    for(int i=0;i<n;i++){
        cin>>petrol[i];
    }
    cout<<"enter distance:"<<endl;
    for(int i=0;i<n;i++){
        cin>>distance[i];
    }
    int ans=circularTour(petrol,distance,n);
    if(ans==-1){
        cout<<"circular tour is not possible"<<endl;
    }
    else{
        cout<<"circular tour is starting from index: "<<ans<<endl;
    }
}