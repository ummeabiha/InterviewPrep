#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    int index = 0;

public:
    // Build binary tree from preorder traversal with -1 as null marker
    TreeNode* buildTree(const vector<int>& preorder) {
        if (index >= preorder.size() || preorder[index] == -1) {
            index++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[index++]);
        node->left = buildTree(preorder);
        node->right = buildTree(preorder);
        return node;
    }

    // DFS
    void preorder(TreeNode* root) { //root->left->right
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root) {  //left->root->right
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void postorder(TreeNode* root) {  //left->right->root
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    //BFS
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

    void levelOrderLines(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // calculate the size of a queue i.e. determine how many nodes are on a certain level
            while (size--) {
                TreeNode* curr = q.front(); 
                q.pop();
                cout << curr->val << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            cout << endl;
        }   
    }

    // Minimum and Maximum Node in Binary Tree
    int findMin(TreeNode* root) {
        if (!root) return INT_MAX; //if we encounter null at any leaf node, return the max int, so that in the final comparison it can be excluded
        return min(root->val, min(findMin(root->left), findMin(root->right))); 
    }

    int findMax(TreeNode* root) {
        if (!root) return INT_MIN;
        return max(root->val, max(findMax(root->left), findMax(root->right)));
    }

    //Find N-th Node in Inorder Traversal
        int nthInorder(TreeNode* root, int n) {
        int count = 0;
        int result = -1;
        inorderHelper(root, n, count, result);
        return result;
    }

    void inorderHelper(TreeNode* root, int n, int& count, int& result) {
        if (!root || count >= n) return;

        inorderHelper(root->left, n, count, result);

        count++;
        if (count == n) {
            result = root->val;
            return;
        }

        inorderHelper(root->right, n, count, result);
    }

    //Check if a Tree is Symmetric (mirror to itself)
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
    
    //Check if a two trees are mirror to each other then call the isMirror with root nodes of two different trees
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);       
    }

    // Search an Item in a Binary Search Tree (left nodes smaller than the right nodes)
    bool searchBST(TreeNode* root, int val) {
        if (!root) return false;
        if (root->val == val) return true;
        if (val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }

    //Find the Height (Depth) of the Tree
    int treeHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }

    //Sum of all nodes
    int sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

};

int main() {
    BinaryTree tree;
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    TreeNode* root = tree.buildTree(preorder);

    cout << "Preorder: ";
    tree.preorder(root);
    cout << "\nInorder: ";
    tree.inorder(root);
    cout << "\nPostorder: ";
    tree.postorder(root);
    cout << "\nLevel Order: ";
    tree.levelOrder(root);
    cout << "\nLevel Order Line by Line:\n";
    tree.levelOrderLines(root);

    cout << "Min: " << tree.findMin(root) << endl;      
    cout << "Max: " << tree.findMax(root) << endl;       
    cout << "3rd Node in Inorder: " << tree.nthInorder(root, 3) << endl;
    return 0;
}
