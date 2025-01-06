//given an array of size N=(2M+1) where M elements are present twice in a array we have to find that
// unique element in array which is present only once
// ex. 5 size, M=2 --> 2 elements present twice; {1,2,2,3,1} --> 3
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){                // xor --> same element after xor gives 0
        ans=ans^arr[i];                  // 1^2^2^3^1=0^3=3
    }
    cout<<"the unique element is "<<ans<<endl;
}
// normal approach (but not recommended)
/*#include<iostream>
using namespace std;
int count(int arr[],int key,int n) {
    int ans=0;
    for(int i=0;i<n;i++){
        if (arr[i]==key){
            ans++;
        }
    }
    return ans;
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
    for(int i=0;i<n;i++){
        int count_=count(arr,arr[i],n);
        if(count_==1){
            cout<<"the unique elements is "<<arr[i]<<endl;
            break;
        }
    }
}*/