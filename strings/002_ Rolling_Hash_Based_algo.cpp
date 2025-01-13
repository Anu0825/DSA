/*The rolling hash approach uses hash functions to efficiently compare different substrings of the original string with
 those of the reversed string. Hashing helps determine if a substring matches another by comparing hash values rather than 
 individual characters.Rolling hashes were designed to handle substring matching and comparison problems by allowing incremental
 updates to hash values as we slide through the string. This reduces the number of comparisons needed by comparing hash values 
 instead of actual substrings.To start, we compute hash values for all prefixes of the original string and all suffixes of the 
 reversed string using a rolling hash function. The rolling hash function allows us to update the hash values incrementally, 
 which speeds up the computation compared to recalculating hashes from scratch.
 Next, we compare the hash values of the prefixes from the original string with the hash values of the suffixes from the reversed
 string. When the hash values match, it indicates that the corresponding substrings are identical. This helps us find the longest
palindromic prefix.

For example: Suppose our string is "aacecaaa". We calculate hash values for the prefixes of "aacecaaa" and the suffixes of
its reverse, "aaacecaa". The hash comparisons reveal that the longest palindromic prefix is "aacecaaa". We then reverse the 
remaining part of the string ("a"), yielding "a". Prepending this reversed part to the original string gives "aaacecaaa".*/
#include <iostream>
#include <string>
using namespace std;
string shortestPalindrome(string s) {
        long long hashBase = 29;
        long long modValue = 1e9 + 7;
        long long forwardHash = 0, reverseHash = 0, powerValue = 1;
        int palindromeEndIndex = -1;

        // Calculate rolling hashes and find the longest palindromic prefix
        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];

            // Update forward hash
            forwardHash =
                (forwardHash * hashBase + (currentChar - 'a' + 1)) % modValue;

            // Update reverse hash
            reverseHash =
                (reverseHash + (currentChar - 'a' + 1) * powerValue) % modValue;
            powerValue = (powerValue * hashBase) % modValue;

            // If forward and reverse hashes match, update palindrome end index
            if (forwardHash == reverseHash) {
                palindromeEndIndex = i;
            }
        }

        // Find the remaining suffix after the longest palindromic prefix
        string suffix = s.substr(palindromeEndIndex + 1);
        // Reverse the remaining suffix
        string reversedSuffix(suffix.rbegin(), suffix.rend());

        // Prepend the reversed suffix to the original string and return the result
        return reversedSuffix + s;
}
int main(){
    string s="aacecaaa";
    cout<<shortestPalindrome(s)<<endl;
    return 0;
}
