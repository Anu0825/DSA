/*#include <iostream>
using namespace std; 
void display(const int constl=5)
{ 
 const int const2=5;
 int arrayl[constl]; 
 int array2[const2]; 
 for(int i=0; i<5; i++) 
 {
 arrayl[i] = i; 
 array2[i] = i*10; 
 cout <<arrayl[i]<<" "<< array2[i] <<" "; 
 }
} 
int main()
{
 display(5);
}*/
/*#include <iostream>
using namespace std; 
int gValue=10; 
void extra() 
{
 cout << gValue << ' ';
}
int main()
{ 
 extra();
 {                             //this brackets rep. local scope 
 int gValue = 20; 
 cout << gValue << ' ';         // output -> 10 20 10
 cout << :: gValue << ' ';
 }
}*/
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}