// The first two terms are hardcoded as 0 and 1. Then, each subsequent term is the sum of the previous two terms.

// Time Complexity: O(n), where n is the number of terms to generate.

#include <iostream>
#include <vector>
using namespace std;

vector<int> fibonacci(int n) {
    vector<int> fib = {0, 1};
    for (int i = 2; i < n; ++i) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}

int main() {
    vector<int> fib = fibonacci(5);
    for (int num : fib) {
        cout << num << " ";  // Output: 0 1 1 2 3
    }
    return 0;
}
