/* LeetCode Day 66: 1026. Maximum Difference Between Node and Ancestor (Medium) 74/75 
 * Tyler Edwards | January 10th, 2024 
 * Code Credit: votrubac
 * Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
 * A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b. */

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
    int maxAncestorDiff(TreeNode* r, int mn = 100000, int mx = 0) {
        if (r == nullptr) return mx - mn;
        mx = max(mx, r->val);
        mn = min(mn, r->val);
        return max(maxAncestorDiff(r->left, mn, mx), 
               maxAncestorDiff(r->right, mn, mx));
        }
};