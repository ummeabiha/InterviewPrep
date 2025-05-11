// The function compares characters from both ends of the string.

// If any mismatch is found, it returns false; otherwise, it returns true when all characters match.

// Time Complexity: O(n), where n is the length of the string.

#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string s) {
    int start = 0, end = s.length() - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    cout << is_palindrome("racecar") << endl;  // Output: 1 (true)
    cout << is_palindrome("hello") << endl;    // Output: 0 (false)
    return 0;
}
