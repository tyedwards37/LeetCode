/* Daily Question: 404. Sum of Left Leaves
 * by Tyler Edwards | April 13th, 2024 
 * Given the root of a binary tree, return the sum of all left leaves. 
 * A leaf is a node with no children. A left leaf is a leaf that is the left child of another node. */

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
    int sum = 0; // intialize a variable for the sum 

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0; // check if the tree is empty and return 0 (also ends the recursive calls to the function)
        if(root->left && !(root->left->left) && !(root->left->right)) sum += root->left->val; // check for a left child and if it has any child nodes, if it doesn't add the left leaf's value to the pre-existing sum

        sumOfLeftLeaves(root->left); // recursively call the function for the root's left child
        sumOfLeftLeaves(root->right); // recursively call the function for the root's right child 
        return sum; // reutrn the final sum after all the recursive calls are done
    }
};