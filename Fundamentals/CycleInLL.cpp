// This code checks if a linked list contains a cycle using Floyd's Cycle Detection Algorithm (also called the tortoise and hare algorithm).

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool has_cycle(Node* head) {
    if (head == nullptr) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head;  // Creating a cycle
    cout << has_cycle(head) << endl;  // Output: 1 (true)
    return 0;
}
