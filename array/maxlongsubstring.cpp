#include<iostream>
using namespace std;
int main(){
    int arr[13]={'a','b','c','d','a','b','a','b','c','d','e','f','b'};
    int n=13;
    int ptr1=0;
    int ptr2=1;
    int cnt=1,maxi=0;
    while(ptr1<n && ptr2<n){
        if(arr[ptr1]==arr[ptr2] || arr[ptr2]==arr[ptr2-1]){
            maxi=max(maxi,cnt);
            cnt=0;
            ptr1++;
            ptr2=ptr1+1;
        }
        cnt++;
        ptr2++;
    }
    cout<<maxi<<endl;
}
