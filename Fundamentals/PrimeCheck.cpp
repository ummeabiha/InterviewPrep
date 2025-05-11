// The function checks divisibility from 2 to sqrt(num). If the number is divisible by any number in this range, it’s not prime.
// Time Complexity: O(√n), where n is the number being checked.

#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    cout << is_prime(7) << endl;   // Output: 1 (true)
    cout << is_prime(10) << endl;  // Output: 0 (false)
    return 0;
}
