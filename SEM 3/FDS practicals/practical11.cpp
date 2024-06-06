// A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters “poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions
// a) To print original string followed by reversed string using stack
// b) To check whether given string is palindrome or not

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

void printReverse(string str) {
    stack<char> Stack;

    for (int i = 0; i < str.length(); i++) {
        Stack.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++) {
        cout << Stack.top();
        Stack.pop();
    }
}

bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    string str = "Poor Dan is in a droop";
    cout << "Original string: " << str << endl;
    printReverse(str);
    cout << "Entered string is " << (isPalindrome(str) ? "a palindrome" : "not a palindrome") << endl;
    return 0;
}
