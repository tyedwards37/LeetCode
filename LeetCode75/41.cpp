/* LeetCode Day 38: Count Good Nodes in Binary Tree (1448) (Medium) 41/75 
 * by Tyler Edwards | December 2nd, 2023 
 * Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
 * Return the number of good nodes in the binary tree. */

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
    int count = 0;

    void dfs(TreeNode* node, int currMax)
    {
        if (!node)
        {
            return;
        }

        if (node->val >= currMax)
        {
            count++;
            currMax = node->val;
        }

        dfs(node->left, currMax);
        dfs(node->right, currMax);
    }

    int goodNodes(TreeNode* root) 
    {
        dfs(root, root->val);
        return count;
    }
};
