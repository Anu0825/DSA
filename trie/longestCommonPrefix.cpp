// given a list of strings. we have to find the longest common prefix
// eg. {"coding","coders","codezen","codingninza"} -> ans= cod
#include<iostream>
#include<vector>
using namespace std;
class trieNode{
    public:
      char data;
      trieNode* children[26];
      int childcnt;
      bool isTerminal;
      trieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcnt=0;
        isTerminal=false;
      }
};
class trie{
    public:
       trieNode* root;
       trie(char ch){
        root= new trieNode(ch);
       }
       void insertUtil(trieNode* root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal= true;
            return;
        }
        int index=word[0]-'a';
        trieNode* child;
        //present
        if(root -> children[index]!=NULL){
            child=root->children[index];
        }
        else{
            // absent
            child=new trieNode(word[0]);
            root -> childcnt++;
            root->children[index]=child;
        }
        //recursive call
         insertUtil(child,word.substr(1));
       }
       void insertWord(string word){
        insertUtil(root,word);
       }
};

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
int main(){
    int size;
    cout<<"enter size:";
    cin>>size;
    vector<string> arr;
    for(int i=0;i<size;i++){
        string str;
        cin>>str;
        arr.push_back(str);
    }
    cout<<"longest common prefix -> "<<longestCommonPrefix(arr,size)<<endl;
}