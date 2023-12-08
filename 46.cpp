/* LeetCode Day 42: 1161. Maximum Level Sum of a Binary Tree (Medium) 46/75 
 * Tyler Edwards | December 7th, 2023 
 * Code Credit: votrubac
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level x such that the sum of all the values of nodes at level x is maximal. */

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
    vector<int> sums;

    void dfs (TreeNode* node, size_t level)
    {
        if (node != nullptr)
        {
            sums.resize(max(sums.size(), level));
            sums[level - 1] += node->val;
            dfs(node->left, level + 1);
            dfs(node->right, level + 1);
        }
    }

    int maxLevelSum(TreeNode* root) 
    {
        dfs(root, 1);
        return distance(begin(sums), max_element(begin(sums), end(sums))) + 1;
    }
};