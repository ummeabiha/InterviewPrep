#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, vector<int>> adj; // Graph as adjacency list

// Tree is a special kind of acyclic graph that is connected and has no cycles.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void treeToGraph(TreeNode* root) {
    if (!root) return;

    /*  If there is a left child:
        Add edge from root to left and from left to root. */
    if (root->left) {
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val); // because it's undirected
        treeToGraph(root->left);
    }

    /*  If there is a right child:
    Add edge from root to right and from right to root. */
    if (root->right) {
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
        treeToGraph(root->right);
    }
}

void printGraph() {
    for (auto& pair : adj) {
        int node = pair.first;
        vector<int>& neighbors = pair.second;

        cout << node << ": ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    treeToGraph(root);
    printGraph();

    // Clean up (not mandatory in short programs but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
