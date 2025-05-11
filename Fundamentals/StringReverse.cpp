// This function swaps characters in the string from both ends, moving towards the middle.

// Time Complexity: O(n), where n is the length of the string.

#include <iostream>
#include <string>
using namespace std;

string reverse_string(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}

int main() {
    string str = "hello";
    cout << reverse_string(str) << endl;  // Output: "olleh"
    return 0;
}
