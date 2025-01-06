#include<iostream>
#include<vector>
using namespace std;
void generateSubarrays(vector<int>& arr) {
    int n = arr.size();

    // Outer loop for starting point
    for (int i = 0; i < n; i++) {
        // Initialize the subarray for each starting point
        vector<int> subarray;
        // Inner loop for extending the subarray
        for (int j = i; j < n; j++) {
            // Add the current element to the subarray
            subarray.push_back(arr[j]);
            // Process the subarray here (e.g., print it)
            for (int elem : subarray) {
                cout << elem << " ";
            }
            cout <<endl;
        }
    }
}
void subArray(vector<int> arr, int n)
{
    // Pick starting point
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";

            cout << endl;
        }
    }
}
// using recursion
// TC O(2^n)
void printSubArrays(vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;
    // Increment the end point and start from 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1);
    // Print the subarray and increment the starting point
    else {
        cout << "[";
        for (int i = start; i < end; i++)
            cout << arr[i] << ", ";
        cout << arr[end] << "]" << endl;
        printSubArrays(arr, start + 1, end);
    }
    return;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    generateSubarrays(arr);
    subArray(arr,n);
    printSubArrays(arr,0,0);
}