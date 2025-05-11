// can apply xor as well apply xor 3 times a= a^b; b=a^b; a=a^b;
// xor work by assigning same bits ->0, diff -> 1


#include <iostream>
using namespace std;

void swap_numbers(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int x = 5, y = 10;
    swap_numbers(x, y);
    cout << "x = " << x << ", y = " << y << endl;  // Output: x = 10, y = 5
    return 0;
}
