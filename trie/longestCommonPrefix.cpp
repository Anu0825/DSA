// given a list of strings. we have to find the longest common prefix
// eg. {"coding","coders","codezen","codingninza"} -> ans= cod
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node {
    Node* links[26];
    bool isEnd = false;
    int childrenCount = 0;
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
        childrenCount++;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        isEnd = true;
    }
    bool isEndOfWord() {
        return isEnd;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    string longestCommonPrefix() {
        string prefix = "";
        Node* node = root;
        while (true) {
            // Stop if there are multiple branches or end of a word is reached
            if (node->childrenCount != 1 || node->isEndOfWord()) {
                break;
            }
            // Find the single child and add it to the prefix
            for (int i = 0; i < 26; i++) {
                if (node->links[i]) {
                    prefix += ('a' + i);
                    node = node->links[i];
                    break;
                }
            }
        }
        return prefix;
    }
};
string findLongestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return ""; 
    Trie trie;
    // Insert all strings into the Trie
    for (string& str : strs) {
        trie.insert(str);
    }
    return trie.longestCommonPrefix();
}

// without using trie
string longestCommonPrefix(vector<string> &arr,int size){
    string ans="";
    //for traversing all characters of first string
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];
        bool match=true;
        //for comparing ch with rest of the strings
        for(int j=1;j<size;j++){
            // not match
            if(arr[j].size()<i || ch!=arr[j][i]){
                match=false;
                break;
            }        
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string lcp = findLongestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << lcp << endl;

    return 0;
}

