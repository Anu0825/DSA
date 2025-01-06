//if ith bit is 1 then reamin as it is if zero convert to 1
#include<iostream>
using namespace std;
int main(){
    int n,bit;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter bit:";
    cin>>bit;
    //using left shift
    n=(n|(1<<bit));
    cout<<n<<endl;
}
