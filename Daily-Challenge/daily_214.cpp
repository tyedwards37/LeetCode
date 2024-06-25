/* Daily Question: 1038. Binary Search Tree to Greater Sum Tree
 * by Tyler Edwards | June 24th, 2024
 * Code Credit: lee215
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
 * As a reminder, a binary search tree is a tree that satisfies these constraints:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees. */

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

class Solution {
public:
    int pre = 0; // intialize an integer to hold the previous value

    TreeNode* bstToGst(TreeNode* root) {
        if (root->right) bstToGst(root->right); // checks if there is a right child to the current node
        pre = root->val = pre + root->val; // update root.val with root.val + pre
        if (root->left) bstToGst(root->left); // checs if there is a left child to the current node
        return root; // return the final version of the tree
    }
};