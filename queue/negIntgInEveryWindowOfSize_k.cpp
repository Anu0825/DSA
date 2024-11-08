// given an array of size n and a positive intg k. find the first -ve  intg for each nd every window
// (contigous subarray) of size k
// eg. {-8,2,3,-6,10} nd k=2 -> ans={-8,0,-6,-6}
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> negIntg(vector<int> &ans, int arr[],int size,int k){
    for(int i=0;i<size;i++){
        for(int j=i;j<(i+k) && j<size;j++){
            if(arr[j]<0){
                ans[i]=arr[j];
                break;
            }
        }
    }
}
vector<int> negIntgUsingDeque(vector<int> &ans, int arr[],int size,int k){
    deque<int> dq;
    // process the window of k size
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            dq.push_back(i);
        }
    }
    //store answer of first k sized window
    if(dq.size()>0){
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    // process for remaining windows
    for(int i=k;i<size;i++){
        //removal
        if(!dq.empty() && (i-dq.front())>=k){
            dq.pop_front();
        }
        // addition
        if(arr[i]<0){
            dq.push_back(i);
        }
        // ans store
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
}
void printFirstNegativeInteger(int arr[], int k, int n)   //optimised approach
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;
 
    for (int i = k - 1; i < n; i++) {
 
        // skip out of window and positive elements
        while ((firstNegativeIndex < i)
               && (firstNegativeIndex <= i - k
                   || arr[firstNegativeIndex] >= 0)) {
            firstNegativeIndex++;
        }
 
        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0) {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }
}
int main(){
    int size,k;
    cout<<"enter size:";
    cin>>size;
    cout<<"enter window k:";
    cin>>k;
    int *arr=new int[size];
    vector<int> ans;
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //negIntg(ans,arr,size,k);
    //negIntgUsingDeque(ans,arr,size,k);
    printFirstNegativeInteger(arr,k,size);
    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }
}