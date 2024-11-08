// given an array of intg. find the num which occur max tymes.
// if the two num having sme freq then return that num which is at lowest index
#include<iostream>
#include<unordered_map>
using namespace std;
int maxFreq(int arr[],int size){
    unordered_map<int,int> cnt;
    int maxfreq=0;
    int maxans=0;
    for(int i=0;i<size;i++){
        cnt[arr[i]]++;
        maxfreq=max(maxfreq,cnt[arr[i]]);
    }
    for(int i=0;i<size;i++){
        if(maxfreq == cnt[arr[i]]){
            maxans=arr[i];
            break;
        }
    }
    return maxans;
}
int main(){
    int size;
    cout<<"enter size:";
    cin>>size;
    int arr[size];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"number with maximum frequency: "<<maxFreq(arr,size)<<endl;
}