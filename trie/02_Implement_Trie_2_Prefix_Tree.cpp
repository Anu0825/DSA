#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndWith=0;
    int cntPrefix=0;
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    void incEnd(){
        cntEndWith++;
    }
    void incPrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
};
class Trie{
    Node *root;
    public: 
       Trie(){
        root=new Node();
       }
       void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->incPrefix();
        }
        node->incEnd();
       }
       //Function to count the number of words equal to a given word
       int countWordsEqualTo(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntEndWith;
       }
       // Function to count the number of words starting with a given prefix
       int countWordsStartingWith(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntPrefix;
    }
    // function to delete a word from trie
    void erase(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};
int main(){
    Trie trie; 
    trie.insert("apple"); 
    trie.insert("app"); 
    cout << "Inserting strings 'apple', 'app' into Trie"<< endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    cout << "Erasing word 'app' from trie"<< endl;
    trie.erase("app"); 
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    return 0; 
}