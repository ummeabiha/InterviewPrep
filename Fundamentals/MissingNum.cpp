// The sum of the first n natural numbers is calculated using the formula n * (n + 1) / 2.

// The difference between the expected sum and the actual sum of the array gives the missing number.

// Time Complexity: O(n), where n is the number of elements in the array.

#include <iostream>
#include <vector>
using namespace std;

int find_missing_number(const vector<int>& arr, int n) {
    int total_sum = n * (n + 1) / 2;
    int array_sum = 0;
    for (int num : arr) {
        array_sum += num;
    }
    return total_sum - array_sum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    cout << find_missing_number(arr, 5) << endl;  // Output: 3
    return 0;
}
