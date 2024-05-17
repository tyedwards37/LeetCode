/* Daily Question: 1325. Delete Leaves With a Given Value
 * by Tyler Edwards | May 16th, 2024 
 * Code Credit: cs_iitian
 * Given a binary tree root and an integer target, delete all the leaf nodes with value target.
 * Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot). */

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr; // end of the recursive looping
        root->left = removeLeafNodes(root->left, target); // set the left child of the current node to the recursive call of the function with the left child node and the target
        root->right = removeLeafNodes(root->right, target); // set the right child of the current node to the recursive call of the function with the right child node and the target
        if (!root->left && !root->right && root->val == target) // checks if its a leaf or not and the value is the same as the target value
            return nullptr; // "delete" the node by returning a nullptr
        return root; // return the curren node
    }
};