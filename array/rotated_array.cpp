#include<iostream>
using namespace std;
void rotate(int arr[],int n,int index){
    int i=index;
    while(i<n){
        swap(arr[i],arr[i+1]);
        i++;
        if(i==(n-1)){
            i=index-1;
            index--;
            n--;
            if(i==-1){
                break;
            }
        }
    }
}
void rotateArray(int arr[],int n,int d){
    for(int i=1;i<=d;i++){
        int temp=arr[0];
        int p=0;
        while(p<n-1){
            arr[p]=arr[p+1];
            p++;
        }
        arr[n-1]=temp;
    }
}
//best approach
void rotated_array(int arr[],int n,int index){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[(i+index)%n]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int n,index;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter index:";
    cin>>index;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //rotate(arr,n,index);
    /*rotated_array(arr,n,index);
    cout<<"rotated array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }*/
    rotateArray(arr,n,index);
    cout<<"rotated array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}