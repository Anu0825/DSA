//given array of size n with elements {1 to n-1} and a no. is present twice --> duplicate elem.
// ex. {1,3,2,4,3} --> 3
//approach 1st count the elem. and print whose count==2
//approach 2nd
/*#include<iostream>
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
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++)
        if((arr[i]^arr[j])==0){
            cout<<"the duplicate element is:"<<arr[i]<<endl;
            break;
        }
    }
}*/
// approach 3rd
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
    for(int i=1;i<n;i++){
        ans=ans^i;
    }
    cout<<"the duplicate element is "<<ans<<endl;
}
