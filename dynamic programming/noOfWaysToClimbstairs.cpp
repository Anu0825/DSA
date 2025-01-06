/*you have given a no. of stairs. Initially u are at 0th stair nd u need to reach nth stair. each tym u can either climb one step from 
0th step to nth step*/
#include<iostream>
using namespace std;
// recursion
int solve(int nstairs,int i=0){
    if(i==nstairs){
        return 1;
    }
    if(i > nstairs){
        return 0;
    }
    return solve(nstairs,i+1)+solve(nstairs,i+2);
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    cout<<solve(n)<<endl;
}