// using KMP (Knuth-Morris-Pratt) algorithm 
/*The KMP algorithm is used for pattern matching within strings. 
The KMP algorithm computes prefix functions to identify substrings that match specific patterns*/
//Find the length of longest prefix which is also a suffix
#include<iostream>
#include<vector>
using namespace std;
int lps(string s){
    vector<int> lps(s.size(),0);
    int pref=0,suf=1;
    while(suf<s.size()){
        // Match
        if(s[pref]==s[suf]){
            lps[suf]=pref+1;
            suf++,pref++;
        }
        // not match
        else{
            if(pref==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pref=lps[pref-1];
            }
        }
    }
    return lps[s.size()-1];
}
int main(){
    string s="abacabadabacaba";
    cout<<lps(s)<<endl;
}
