// Write a program to evaluate to 0.0001% accuracy
// SUM= 1+ (1/2)^2+ (1/3)^3+ (1/4)^4+ _ _ _ 
#include<iostream>
using namespace std;
double power(double a,int b){
    if (b==0){
        return 1;
    }
    return a*power(a,b-1);
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    double sum=0,result;
    for(int i=1;i<=n;i++){
        result=power(1.0/i,i);
        cout<<result<<endl;
        sum=sum+result;
    }
    cout<<"the sum of given series is: "<<sum<<endl;
}