/* Daily Question: 938. Range Sum of BST
 * by Tyler Edwards | January 7th, 2024 
 * Code Credit: archit91
 * Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high]. */

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
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        return  (root -> val >= L && root -> val <= H ? root -> val : 0) +  
                rangeSumBST(root -> left, L, H) +  
                rangeSumBST(root -> right, L, H); 
    }
};