#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* insertLevelOrder(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();

        if (!curr->left) {
            curr->left = new TreeNode(val);
            break;
        } else {
            q.push(curr->left);
        }

        if (!curr->right) {
            curr->right = new TreeNode(val);
            break;
        } else {
            q.push(curr->right);
        }
    }

    return root;
}

void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    insertLevelOrder(root, 2);
    insertLevelOrder(root, 3);
    insertLevelOrder(root, 4);
    insertLevelOrder(root, 5);

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
