// This is a recursive approach. The base case is factorial(0) = 1.

// Each recursive call multiplies the number n by the factorial of n-1.

// Time Complexity: O(n), where n is the number for which the factorial is computed.

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5) << endl;  // Output: 120
    return 0;
}
