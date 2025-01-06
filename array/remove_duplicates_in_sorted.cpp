//space comp  --> O(1)
//time comp --> O(n)
#include<iostream>
using namespace std;
int duplicates_elem(int arr[],int n){
    int i=0,j=1;
    while(j<n){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
        j++;
    }
    return i+1;
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
    int cnt=duplicates_elem(arr,n);
    cout<<"the no. of unique elements: "<<cnt<<endl;
    for(int j=cnt;j<n;j++){
        arr[j]=0;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


// space comp --> n
// time comp --> nlogn
/* #include<iostream>
#include<set>
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
    set<int> st;
    for(int i=0;i<n;i++){
       st.insert(arr[i]);       //for this time comp --> O(n)=nlogn
    }
    int index=0;
    for(auto i:st){
        arr[index]=i;          //for this time comp=n
        index++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
*/