/* LeetCode Day 14: Leaf-Similar Trees (Easy) 16/75 
 * by Tyler Edwards | November 7th, 2023 
 * Desc: Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar. */

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
    #include <vector>
    
    void leafFinder(TreeNode* root, vector<int>& leaves)
    {
        if (!root)
        {
            return;
        }

        if (!(root->left || root->right))
        {
            leaves.push_back(root->val);
        }

        leafFinder(root->left, leaves);
        leafFinder(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leaves1;
        vector<int> leaves2;

        leafFinder(root1, leaves1);
        leafFinder(root2, leaves2);

        return leaves1 == leaves2;
    }
};