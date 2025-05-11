// The function iterates through the array and keeps track of the largest element.
// Time Complexity: O(n), where n is the size of the array.


// One of the approach is to sort the array and then get the last element of the sorted array -> complexity will be dependent on the chosen sorted algo 

#include <iostream>
#include <vector>
using namespace std;

int find_largest_element(const vector<int>& arr) {
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << find_largest_element(arr) << endl;  // Output: 5
    return 0;
}
