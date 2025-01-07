#include <iostream>
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
    
    // Method to find the maximum XOR value for a given number
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0; 
        // Iterate through each bit of the number (from left to right)
        for (int i = 31; i >= 0; i--) { 
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1; 
            // If the complement of the current bit exists in the Trie
            if (node->containsKey(1 - bit)) { 
                // Update the maximum XOR value by updating the value of bit to 1
                maxNum |= (1 << i); 
                 // Move to the child node corresponding to the complement of the current bit
                node = node->get(1 - bit);
            } else {
                 // Move to the child node corresponding to the current bit
                node = node->get(bit);
            }
        }
        return maxNum; 
    }
};

// Function to find the maximum XOR value between two sets of numbers
int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    Trie trie; 
    for (auto& it : arr1) { 
        trie.insert(it);
    }
    int maxi = 0; 
    for (auto& it : arr2) { 
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}

void printArr(vector<int> arr){
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {3, 10, 5, 25, 2};
    vector<int> arr2 = {8, 1, 2, 12, 7};
    int n = arr1.size();
    int m = arr2.size();
    
    cout << "Arr1: ";
    printArr(arr1);
    cout << "Arr2: ";
    printArr(arr2);
    

    int result = maxXOR(n, m, arr1, arr2);
    cout << "Maximum XOR value: " << result << endl;

    return 0;
}