// an election is contested by five candidates numbered 1 to 5 and voting is done by marking cand. no. on
// ballot ppr.WAP to read ballots and count the votes cast for each candidate using array variable count.
//if no. is outside range 1 to 5,ballot should be considered as spoilt ballot and count sp. ballot also.
#include<iostream>
using namespace std;
int main(){;
    int n;
    cout<<"enter no. of candidates:";
    cin>>n;
    int count[6]={0},ballot;
    for(int i=1;i<=n;i++){
        cin>>ballot;                     //or what we can do is:
        switch(ballot){                  // if(ballot>0 &&  ballot<6) --> count[i]++;
            case 1: count[1]++;          // else count[0]++;
                    break;
            case 2: count[2]++;
                    break;
            case 3: count[3]++;
                    break;
            case 4: count[4]++;
                    break;
            case 5: count[5]++;
                    break;
            // spoilt ballot
            default: count[0]++;
        }
    }
    for(int i=0;i<6;i++){
       cout<<count[i]<<" ";
    }
}