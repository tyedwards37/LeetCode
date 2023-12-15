/* LeetCode Day 13: Maximum Depth of Binary Tree (Easy) 15/75 
 * by Tyler Edwards | November 6th, 2023 
 * Desc: Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. */

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

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        int depth;
        if (root == NULL)
        {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (leftDepth > rightDepth)
        {
            return leftDepth + 1;
        }

        else
        {
            return rightDepth + 1;
        }
    }
};
