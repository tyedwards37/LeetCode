/* Daily Question: 979. Distribute Coins in Binary Tree
 * by Tyler Edwards | May 17th, 2024 
 * Code Credit: Codensity_30
 * You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.
 * In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.
 * Return the minimum number of moves required to make every node have exactly one coin. */

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
    int distributeCoins(TreeNode* r, TreeNode* p = nullptr) {
        if (r == nullptr) return 0; // return 0 to end the recursive calls, if the given node is NULL
        int res = distributeCoins(r->left, r) + distributeCoins(r->right, r); // set an answer int to add the recusrive calls of the function on the left and right child
        if (p != nullptr) p->val += r->val - 1; // if the value isn't equal to NULL set the value of p to the value of r - 1
        return res + abs(r->val - 1); // return the answer value + the absolute value of the r node minus 1 
    }
};