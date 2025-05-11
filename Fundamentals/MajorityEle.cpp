#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majority_element(vector<int>& arr) {
    unordered_map<int, int> freq_map;
    for (int num : arr) {
        freq_map[num]++;
        if (freq_map[num] > arr.size() / 2) {
            return num;
        }
    }
    return -1;  // No majority element
}

int main() {
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << majority_element(arr) << endl;  // Output: 4
    return 0;
}
