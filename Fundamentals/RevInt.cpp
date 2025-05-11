// The function reverses the digits by repeatedly taking the remainder (num % 10) and building the reversed number.

// Time Complexity: O(d), where d is the number of digits in the integer.

#include <iostream>
using namespace std;

int reverse_integer(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    cout << reverse_integer(12345) << endl;  // Output: 54321
    return 0;
}
