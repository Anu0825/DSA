// to find the gcd or hcf of a no.
#include<iostream>
using namespace std;
int gcd(int a, int b)   //Basic Euclidean Algorithm
{                       // TC: O(log min(a,b))
    if (a == 0)         // SC: O(log min(a,b))
        return b;
    return gcd(b % a, a);
}
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0)            //extended euclidean theorem
    {                      // TC:O(log n)
        *x = 0;            // SC: O(log n)
        *y = 1; 
        return b; 
    } 

    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    // Update x and y using results of recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
// Iterative function to return gcd of a and b
int gcd_(int a, int b)             // TC: O(log(min(a,b)))
{                                  // SC: O(1)
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

int main(){
    int a,b;
    cout<<"enter a and b:";
    cin>>a>>b;
    for(int i=((a>b)?b:a);i>0;i--){
        if((a%i==0) && (b%i==0)){
             cout<<i<<endl;
             break;
        }
    }
    cout<<gcd(a,b)<<endl;
    int x,y;
    cout<<gcdExtended(a,b,&x,&y)<<endl;
    cout<<gcd_(a,b)<<endl;
}