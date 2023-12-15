/* Daily Question: 94. Binary Tree Inorder Traversal
 * by Tyler Edwards | December 8th, 2023 
 * Code Credit: jianchao-li
 * Given the root of a binary tree, return the inorder traversal of its nodes' values. */

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
    void inorder(TreeNode* node, vector<int>& nodes)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, nodes);
        nodes.push_back(node->val);
        inorder(node->right, nodes);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
};
