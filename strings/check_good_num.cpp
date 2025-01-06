/*A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).*/
#include <iostream>
#include <string>
#include <vector>

// Function to check if a digit is prime
bool isPrimeDigit(char c) {
    return (c == '2' || c == '3' || c == '5' || c == '7');
}

// Function to check if a digit is even
bool isEvenDigit(char c) {
    return (c == '0' || c == '2' || c == '4' || c == '6' || c == '8');
}

// Function to check if the string is a good number based on the given conditions
bool isGoodNumber(const std::string& str) {
    // Iterate over each digit in the string
    for (int i = 0; i < str.length(); i++) {
        char currentDigit = str[i];
        if (i % 2 == 0) {  // Even index
            if (!isEvenDigit(currentDigit)) {
                return false;  // Digit at even index is not even
            }
        } else {  // Odd index
            if (!isPrimeDigit(currentDigit)) {
                return false;  // Digit at odd index is not prime
            }
        }
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a digit string: ";
    std::cin >> input;

    if (isGoodNumber(input)) {
        std::cout << "\"" << input << "\" is a good number.\n";
    } else {
        std::cout << "\"" << input << "\" is not a good number.\n";
    }

    return 0;
}
