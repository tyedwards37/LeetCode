/* Daily Question: 1261. Find Elements in a Contaminated Binary Tree
 * by Tyler Edwards | February 20th, 2025 
 * Code Credit: dsmn
 * Given a binary tree with the following rules:
 * 1. root.val == 0
 * 2. For any treeNode:
 *   1. If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
 *   2. If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
 * Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
 * Implement the FindElements class:
 * - FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
 * - bool find(int target) Returns true if the target value exists in the recovered binary tree. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    unordered_set<int> set;
public:
    void recover(TreeNode* root, int x) {
        if (!root) return;
        root->val = x;
        set.emplace(x);
        recover(root->left, 2 * x + 1);
        recover(root->right, 2 * x + 2);
    }
    
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return set.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */