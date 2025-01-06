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
    int min=arr[0];    // min=INT_MAX --> (2^31)-1
    for(int i=0;i<n;i++){
        if (arr[i]<min){  // at place of if block we can use min_=min(min_,arr[i])
            min=arr[i];
        }
    }
    cout<<"the maximum element is: "<<min<<endl;
}
/*
#include <bits/stdc++.h>
using namespace std;

int getMin(int arr[], int n)
{
    // If there is single element, return it.
    // Else return minimum of first element and
    // minimum of remaining array.
    return (n == 1) ? arr[0] : min(arr[0], 
                         getMin(arr + 1, n - 1));
}

int getMax(int arr[], int n)
{
    // If there is single element, return it.
    // Else return maximum of first element and
    // maximum of remaining array.
    return (n == 1) ? arr[0] : max(arr[0], 
                          getMax(arr + 1, n - 1));
}

int main()
{
    int arr[] = { 12, 1234, 45, 67, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum element of array: " << 
                            getMin(arr, n) << "\n";
    cout << "Maximum element of array: " << 
                                   getMax(arr, n);
    return 0;
}
*/