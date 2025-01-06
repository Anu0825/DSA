/*Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.

Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]

Output: 113
*/
#include<iostream>
using namespace std;
bool isallowed(int arr[],int n,int m,int mid){
    int studentcnt=1;
    int pagesum=0;
    for(int i=0;i<n;i++){
        if(pagesum + arr[i]<=mid){
            pagesum+=arr[i];
    }
    else{
        studentcnt++;
        if(studentcnt > m || arr[i]> mid){
            return false;
        }
        pagesum =arr[i];
    }
    }
    return true;
}
int binary_search(int start,int end,int arr[],int m,int n){
        int mid=start+(end-start)/2;
        int ans=-1;
        while(start<=end){
            if(isallowed(arr,n,m,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
int main(){
    int n=4,m=2;
    int arr[4]={12,34,67,90};
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=arr[i];
    }
    cout<<binary_search(0,sum,arr,m,n);
}