/* Daily Question: 129. Sum Root to Leaf Numbers
 * by Tyler Edwards | April 14th, 2024 
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 * Each root-to-leaf path in the tree represents a number.
 * - For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
 * A leaf node is a node with no children. */

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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0); // call to a depth-first search with the root and the starting value of 0
    }

    int dfs(TreeNode* root, int cur) {
        if(!root) return 0; // checks to end the recursive loop
        cur = cur * 10 + root -> val; // append current node's digit to the total value
        if(!root -> left && !root -> right)  // check if its a leaf node 
            return cur; // return the current total value 
        return dfs(root -> left, cur) + dfs(root -> right, cur); // recurse for child if current node is not leaf
    }  
};