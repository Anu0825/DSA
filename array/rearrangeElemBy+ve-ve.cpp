//given an array. we have to rearrange the elements in the array like 1st one positive then one neg.
// order must be sme nd array has equal no. of +ve nd -ve elem.
// eg. {3,1,-2,-5,2,-4} -> {3,-2,1,-5,2,-4}
//incomplete
#include<iostream>
#include<vector>
using namespace std;
void rearrangeElem(int arr[],int size){
    vector<int> positive;
    vector<int>negative;
    for(int i=0;i<size;i++){
        if(arr[i]>0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    for(int i=size-2;i>=0;i=i-2){
        arr[i]=positive.back();
        positive.pop_back();
    }
    for(int i=size-1;i>=1;i=i-2){
        arr[i]=negative.back();
        negative.pop_back();
    }
}
int main(){
    int size;
    cout<<"enter size:";
    cin>>size;
    int *arr=new int[size];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    rearrangeElem(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}