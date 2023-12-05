/* LeetCode Day 39: Longest ZigZag Path in a Binary Tree (1372) (Medium) 43/75 
 * Tyler Edwards | December 4th, 2023 
 * Code Credit: hiepit
 * You are given the root of a binary tree.
 * A ZigZag path for a binary tree is defined as follow:
 * - Choose any node in the binary tree and a direction (right or left).
 * - If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
 * - Change the direction from right to left or from left to right.
 * - Repeat the second and third steps until you can't move in the tree.
 * Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
 * Return the longest ZigZag path contained in that tree. */

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
    int longest = 0;
    void dfs(TreeNode* node, bool goingLeft, int currCount)
    {   
        if (!node)
        {
            return;
        }

        longest = max(longest, currCount);

        if (goingLeft)
        {
            dfs(node->left, false, currCount + 1);
            dfs(node->right, true, 1);
        }

        else
        {
            dfs(node->right, true, currCount + 1);
            dfs(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) 
    {
        dfs(root, true, 0);
        dfs(root,false, 0);
        return longest;
    }
};