/* Given an array of non-negative integers and an array of queries where each query is a pair of two 
non-negative integers ie. [Xi, Ai]The answer to the ith query is the maximum bitwise XOR value of the
Xi with any integer less than or equal to Ai in the array.Return an array consisting of the results of 
these queries. Note: If all integers are greater than ‘Ai’ in array/list ‘ARR’ then the answer to this 
with the query will be -1.*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
    // Array to store links to child nodes (0 and 1)
    Node* links[2]; 
    bool containsKey(int bit) {
        return (links[bit] != NULL); 
    }
    Node* get(int bit) {
        return links[bit]; 
    }
    void put(int bit, Node* node) {
        links[bit] = node; 
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root; 
        for (int i = 31; i >= 0; i--) { 
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1; 
            // If the current node doesn't have a child node with the current bit
            if (!node->containsKey(bit)) { 
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }

public:
    int findMax(int num) {
        Node* node = root; 
        int maxNum = 0; 
        for(int i = 31; i >= 0; i--) {
             // Extract the i-th bit of the number
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit); 
            }
            else {
                node = node->get(bit); 
            }
        }
        return maxNum; 
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> ans(queries.size(), 0); 
    // Vector to store offline queries
    vector<pair<int, pair<int,int>>> offlineQueries;
    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0; 
    int n = arr.size(); 
    Trie trie; 
    for(auto &it : offlineQueries) {
        // Insert numbers into the trie until the current query's end point
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]); 
            i++; 
        }
        // If there are numbers inserted into the trie, find the maximum XOR value for the query range
        if(i != 0) 
            ans[it.second.second] = trie.findMax(it.second.first); 
        else 
            // If no numbers inserted, set result to -1
            ans[it.second.second] = -1; 
    }
    return ans; 
}


int main() {
    vector<int> arr = {3, 10, 5, 25, 2, 8}; 
    cout << "Given Array: ";
    for(int i =0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    
    cout << "Queries: ";
    for(auto query: queries){
       cout << query[0] << " " << query[1] << ", ";
    }
    cout << endl;
    
    vector<int> result = maxXorQueries(arr, queries);

    cout << "Result of Max XOR Queries:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Query " << i+1 << ": " << result[i] << endl;
    }

    return 0;
}