#include<iostream>
using namespace std;
void print_array(int n,int arr[]){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void array(int arr[],int n){  //here arr also represents address of arr[0] thats why it is passing by reference.
    arr[0]=27;                // changes made in function will also reflect in org array.
    cout<<"in the funtion after updating a value:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int main(){
    int arr[3]; //arr of size 3 indexing from 0 to 2
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    cout<<"array elements are:"<<endl;
    print_array(3,arr);
    cout<<"addresses of array elements are:"<<endl; //contiguous memory allocation
    for(int i=0;i<3;i++){
        cout<< &arr[i]<<" ";
    } cout<<endl;
    /* int n;
    //static memory allocation
    int arr1[n]; // not a good practice to take array size as a input */
    int arr2[5]={0}; //intializing all elements with 0 {0,0,0,0,0}
    cout<<"array2 elements are:"<<endl;
    print_array(5,arr2);
    int arr3[4]={1,2,3,4};  //intialize elements with given values {1,2,3,4}
    cout<<"array3 elements are:"<<endl;
    print_array(4,arr3);
    int arr4[3]; // initialize all elements with garbage value if not initialized
    cout<<"array 4 elements are:"<<endl;
    print_array(3,arr4);
    int arr5[5]={1}; // we can't initialize all elem by a specific value by this method except zero
    //it will give others zero by default {1,0,0,0,0}
    // int arr[5]={2,7} --> {2,7,0,0,0}
    cout<<"array 5 elements are:"<<endl;
    print_array(5,arr5);
    int arr6[10]; 
    cout<<"array 6 elements are:"<<endl;
    fill_n(arr6,10,3); //initialize all elem. by specific value {3,3,3,3,3,3,3,3,3,3}
    print_array(10,arr6);
    int size_arr3=sizeof(arr3)/sizeof(int); //find the size of array
    cout<<"size of array 3 is: "<<size_arr3<<endl; 
    char arr7[4]={'a','b','c','d'};   //char array
    // similarly we can define array of any data type like float,double.
    cout<<"array 7 elements are:"<<endl;
    for(int i=0;i<4;i++){
        cout<<arr7[i]<<" ";
    }


// SCPOES OF ARRAY
    int arr8[4]={1,2,3,4};
    cout<<"array 8 elements:"<<endl;
    array(arr8,4);
    cout<<"outside the function"<<endl;
    for(int i=0;i<4;i++){
        cout<<arr8[i]<<" ";
    } cout<<endl;
}