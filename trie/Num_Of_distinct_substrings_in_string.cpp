#include <iostream>  
#include <set>
#include <string>    
using namespace std;  
struct Node {
    Node* links[26];  
    bool flag = false;  
    bool containsKey(char ch) {  
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch) {  
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {  
        links[ch - 'a'] = node;
    }
    void setEnd() {  
        flag = true;
    }
    bool isEnd() {  
        return flag;
    }
};
int countDistinctSubstrings(string &s) {  
    Node* root = new Node();  
    int cnt = 0;  
    int n = s.size();  
    for (int i = 0; i < n; i++) {  
        Node* node = root;  
        for (int j = i; j < n; j++) {  
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());  
                cnt++;  
            }
            node = node->get(s[j]);  
        }
    }
     //+1 to account for the empty string
    return cnt + 1;  
}

// 2nd method using set
int countDistinctSubstrings2(string &s) {   
    set<string> st;
    int n=s.size();
    for (int i = 0; i < n; i++) {  
        string pref="";
        for (int j = i; j < n; j++) {  
            pref+=s[j];
            st.insert(pref);  
        }
    }
     //+1 to account for the empty string
    return st.size() + 1;  
}

int main() {  
    string s = "ababa";  
    cout << "Current String: " << s << endl;
    cout << "Number of distinct substrings: " << countDistinctSubstrings(s) << endl;  
    cout << "Number of distinct substrings: " << countDistinctSubstrings2(s) << endl;
    return 0;  
}
                                
                            