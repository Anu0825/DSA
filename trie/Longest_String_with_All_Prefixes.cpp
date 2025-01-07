#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
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
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfAllPrefixesExist(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                if (!node->isEnd() && i < word.size() - 1) {
                    return false; // If it's not the last character, it should be a complete word
                }
            } else {
                return false; // Prefix does not exist in the Trie
            }
        }
        return true; // All prefixes exist and are complete words
    }
};

string completeString(vector<string>& arr, int n) {
    Trie trie;
    for (auto& it : arr) {
        trie.insert(it);
    }
    string longest = "";
    for (auto& it : arr) {
        if (trie.checkIfAllPrefixesExist(it)) {
            if (it.length() > longest.length()) {
                longest = it;
            } else if (it.length() == longest.length() && it < longest) {
                longest = it;
            }
        }
    }
    if (longest == "") return "None";
    return longest;
}

int main() {
    int n = 4;
    vector<string> arr = {"geeks", "geeksforgeeks", "geeksfor", "geek"};
    cout << completeString(arr, n) << endl;
}
