// - This uses the two-pointer technique to merge sorted arrays.
// - **Time Complexity:** O(n + m), where `n` and `m` are the lengths of the arrays.


#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_arrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }
        return merged;
    }

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
    vector<int> result = merge_arrays(a, b);
    for (int num : result) cout << num << " ";
    return 0;
}
