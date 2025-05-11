// The function computes the sum by extracting each digit using modulus (num % 10) and reducing the number by dividing it by 10.

// Time Complexity: O(d), where d is the number of digits.

#include <iostream>
using namespace std;

int sum_of_digits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    cout << sum_of_digits(12345) << endl;  // Output: 15
    return 0;
}
