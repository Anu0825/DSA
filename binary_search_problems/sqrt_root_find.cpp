// find the sqr root of a given value
// by using binary search
#include<iostream>
using namespace std;
//function to find the intg value
int sqrt_intg(int n){
    int start=0,end=n;
    int mid=(start+end)/2;
    int ans=-1;
    while(start<=end){
        if((mid*mid)==n){
            return mid;
        }
        if((mid*mid)<n){
            ans=mid;
            start=mid+1;
        }
        else
        end=mid-1;
        mid=(start+end)/2;
    }
    return ans;
}
//function to find decimal value after intg
double more_precision(int ans,int n,int precision){
    double factor=1;
    double res=ans;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=res;j*j<n;j=j+factor){
            res=j;
        }
    }
    return res;
}
int main(){
    int n,precision;
    cout<<"enter value: ";
    cin>>n;
    cout<<"enter precision: ";
    cin>>precision;
    int ans=sqrt_intg(n);
    cout<<"the sqrt is "<<more_precision(ans,n,precision)<<endl;
}