// This is based on the Euclidean algorithm, which repeatedly replaces the larger number by the remainder of the division of the two numbers.

// Time Complexity: O(log(min(a, b))).

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cout << gcd(56, 98) << endl;  // Output: 14
    return 0;
}
