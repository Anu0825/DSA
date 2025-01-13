/*Developed to address the problem of finding palindromic substrings efficiently, Manacher’s algorithm preprocesses the string
 to handle both even and odd-length palindromes uniformly. By inserting special characters between each character of the original 
 string, it computes the radius of the longest palindromic substring centered at each position.
 To handle palindromes of both even and odd lengths uniformly, the algorithm transforms the original string by inserting special 
 characters (e.g., "#") between every character and at the boundaries. This way, every palindrome can be treated as if it’s surrounded
 by characters, making it easier to apply the same expansion logic for all cases.

For example, the string "aacecaaa" is transformed into "^#a#a#c#e#c#a#a#a#$". Here, ^ and $ are boundary markers that help avoid
 out-of-bound errors. # helps to treat the string uniformly, making every palindrome appear with a single center.

Manacher’s algorithm maintains an array P where P[i] denotes the radius of the longest palindromic substring centered at the 
position i in the transformed string.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string shortestPalindrome(string s) {
        // Return early if the string is null or empty
        if (s.empty()) {
            return s;
        }

        // Preprocess the string to handle palindromes uniformly
        string modifiedString = preprocessString(s);
        int n = modifiedString.size();
        vector<int> palindromeRadiusArray(n, 0);
        int center = 0, rightBoundary = 0;
        int maxPalindromeLength = 0;

        // Iterate through each character in the modified string
        for (int i = 1; i < n - 1; ++i) {
            int mirrorIndex = 2 * center - i;

            // Use previously computed values to avoid redundant calculations
            if (rightBoundary > i) {
                palindromeRadiusArray[i] =
                    min(rightBoundary - i, palindromeRadiusArray[mirrorIndex]);
            }

            // Expand around the current center while characters match
            while (modifiedString[i + 1 + palindromeRadiusArray[i]] ==
                   modifiedString[i - 1 - palindromeRadiusArray[i]]) {
                ++palindromeRadiusArray[i];
            }

            // Update the center and right boundary if the palindrome extends beyond the current boundary
            if (i + palindromeRadiusArray[i] > rightBoundary) {
                center = i;
                rightBoundary = i + palindromeRadiusArray[i];
            }

            // Update the maximum length of palindrome starting at the beginning
            if (i - palindromeRadiusArray[i] == 1) {
                maxPalindromeLength =
                    max(maxPalindromeLength, palindromeRadiusArray[i]);
            }
        }

        // Construct the shortest palindrome by reversing the suffix and prepending it to the original string
        string suffix = s.substr(maxPalindromeLength);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }

string preprocessString(const string& s) {
        // Add boundaries and separators to handle palindromes uniformly
        string result = "^";
        for (char c : s) {
            result += "#" + string(1, c);
        }
        result += "#$";
        return result;
}
int main(){
    string s="aacecaaa";
    cout<<shortestPalindrome(s)<<endl;
    return 0;
}