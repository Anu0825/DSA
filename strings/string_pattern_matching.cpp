#include <iostream>
#include <vector>
using namespace std;

// Build LPS array
vector<int> buildLPS(string pattern) {
    vector<int> lps(pattern.size(),0);
    int pref=0,suf=1;
    while(suf<pattern.size()){
        // Match
        if(pattern[pref]==pattern[suf]){
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
    return lps;
}

// KMP Search
void KMP(string text, string pattern) {
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == pattern.size()) {
            cout << "Found at: " << i - j << endl;
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pattern[j]) {
            j = (j > 0) ? lps[j - 1] : 0;
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    KMP(text, pattern);
    return 0;
}
