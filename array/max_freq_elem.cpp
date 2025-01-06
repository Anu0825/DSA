#include <bits/stdc++.h>
using namespace std;
//time comp -> O(n^2) nd spc comp -> O(1)
int maxfreqElem1(int arr[],int n){
    int maxcount=0,maxfreqelem;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>maxcount){
            maxcount=count;
            maxfreqelem=arr[i];
        }
    }
    return maxfreqelem;
}
//time comp -> O(nlogn) nd spc comp -> O(1)
int maxfreqElem2(int arr[],int n){
    // sort array
    sort(arr,arr+n);
    int maxcount=0,maxfreqelem,count;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            count=0;
        }
        if(count>maxcount){
            maxcount=count;
            maxfreqelem=arr[i];
        }
    }
    return maxfreqelem;
}
// time comp -> O(n) nd spc comp -> O(n)
int maxfreqElem3(int arr[],int n){
    unordered_map<int,int> hash;
    int maxcount=0,maxfreqelem;
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(auto i:hash){
        if(i.second>maxcount){
            maxcount=i.second;
            maxfreqelem=i.first;
        }
    }
    return maxfreqelem;
}
// time comp -> O(n) nd spc comp -> O(1)
int maxfreqElem4(int arr[], int n) { 
    //using moore's voting algorithm 
    int res = 0; 
    int count = 1; 
    for(int i = 1; i < n; i++) { 
        if(arr[i] == arr[res]) { 
            count++; 
        } else { 
            count--; 
        } 
          
        if(count == 0) { 
            res = i; 
            count = 1; 
        } 
          
    } 
    return arr[res]; 
} 
  
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"max frequent elem is: "<<maxfreqElem1(arr,n)<<endl;
    cout<<"max frequent elem is: "<<maxfreqElem2(arr,n)<<endl;
    cout<<"max frequent elem is: "<<maxfreqElem3(arr,n)<<endl;
    cout<<"max frequent elem is: "<<maxfreqElem4(arr,n)<<endl;
}


