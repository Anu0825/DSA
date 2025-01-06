#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    string res = "";
    cout << "Enter string: ";
    cin >> str; 
    int i = 0;
    while(i < str.size()) {
        char ch = str[i];
        
        if (isdigit(ch)) {
            int cnt = ch - '0';
            i++;
            if (str[i] == '[') {
                i++;
                string ans = "";
                
                // Extract the string inside the brackets
                while (str[i] != ']' && i < str.size()) {
                    ans += str[i];
                    i++;
                }
                
                // Repeat the extracted string 'cnt' times
                while (cnt > 0) {
                    res += ans;
                    cnt--;
                }
                i++;  // Move past the ']'
            }
        } else {
            // If the character is not a digit, just add it to the result
            res += ch;
            i++;
        }
    }
    
    // Output the decoded string
    cout << res << endl;
    
    return 0;
}
