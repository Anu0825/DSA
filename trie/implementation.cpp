// time comp. for insertion O(l) -> l=length of word
// time comp. for searching O(l) -> l= length of word
#include<iostream>
using namespace std;
class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;
        // constructor
        trieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};
class trie{
    public:
       trieNode* root;
       trie(){
        root= new trieNode('\0');
       }
       void insertUtil(trieNode* root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal= true;
            return;
        }
        // assumption word will be in capital letters
        int index=word[0]-'A';
        trieNode* child;
        //present
        if(root -> children[index]!=NULL){
            child=root->children[index];
        }
        else{
            // absent
            child=new trieNode(word[0]);
            root->children[index]=child;
        }
        //recursive call
         insertUtil(child,word.substr(1));
       }
       void insertWord(string word){
        insertUtil(root,word);
       }

       bool searchUtil(trieNode* root,string word){
        // base case
        if(word.length()==0){
            return root-> isTerminal;
        }
        int index=word[0]-'A';
        trieNode* child;
        //present
        if(root -> children[index]!=NULL){
            child=root->children[index];
        }
        else{
            // absent
           return false;
        }
        //recursive call
        return searchUtil(child,word.substr(1));
       }

       bool searchWord(string word){
        return searchUtil(root,word);
       }

       bool prefixUtil(trieNode* root,string word){
        // base case
        if(word.length()==0){
            return true;
        }
        int index=word[0]-'A';
        trieNode* child;
        //present
        if(root -> children[index]!=NULL){
            child=root->children[index];
        }
        else{
            // absent
           return false;
        }
        //recursive call
        return prefixUtil(child,word.substr(1));
       }

       bool startWith(string prefix){
        return prefixUtil(root,prefix);
       }
};
int main(){
    trie *t=new trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"present or not -> "<<t->searchWord("TIME")<<endl;
    cout<<"present or not -> "<<t->searchWord("TIM")<<endl;
    cout<<"present or not -> "<<t->searchWord("ABC")<<endl;
    cout<<"prefix present or not -> "<<t->startWith("TIM")<<endl;
    return 0;
}