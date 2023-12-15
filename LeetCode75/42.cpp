/* LeetCode Day 39: Path Sum III (437) (Medium) 42/75 
 * by Tyler Edwards | December 3rd, 2023 
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes). */

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

    int dfs(TreeNode* node, long start, int target)
    {
        if (!node)
        {
            return 0;
        }
        
        long currVal = start + node->val;

        return (currVal == target) + dfs(node->left, currVal, target) + dfs(node->right, currVal, target);
    }

    int pathSum(TreeNode* root, int targetSum) 
    {
        if (!root)
        {
            return 0;
        }

        return dfs(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
