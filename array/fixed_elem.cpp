//Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, 
//if there is any Fixed Point present in the array, it returns -1. Fixed Point in an array is an index i such that arr[i] equals i.
// Note that integers in the array can be negative
#include<iostream>
using namespace std;
int fixedelemUsinglinearsearch(int arr[],int n){
    for(int i=0;i<n;i++){
        if(i==arr[i]){
            return i;
        }
    }
    return -1;
}
// C program to check fixed point
// in an array using binary search
#include <stdio.h>

int fixedelemUsingbinarySearch(int arr[], int low, int high)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (mid == arr[mid])
            return mid;
        int res = -1;
        if (mid + 1 <= arr[high])
            res = fixedelemUsingbinarySearch(arr, (mid + 1), high);
        if (res != -1)
            return res;
        if (mid - 1 >= arr[low])
            return fixedelemUsingbinarySearch(arr, low, (mid - 1));
    }

    /* Return -1 if there is no Fixed Point */
    return -1;
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
    cout<<"fixed element is:"<<fixedelemUsinglinearsearch(arr,n)<<endl;
    cout<<"fixed element is:"<<fixedelemUsingbinarySearch(arr,0,n-1)<<endl;
}