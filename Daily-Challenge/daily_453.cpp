/* Daily Question: 889. Construct Binary Tree from Preorder and Postorder Traversal
 * by Tyler Edwards | February 22nd, 2025 
 * Code Credit: lee
 * Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
 * If there exist multiple answers, you can return any of them. */

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
        int preIndex = 0, posIndex = 0;
        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
            TreeNode* root = new TreeNode(pre[preIndex++]);
            if (root->val != post[posIndex])
                root->left = constructFromPrePost(pre, post);
            if (root->val != post[posIndex])
                root->right = constructFromPrePost(pre, post);
            posIndex++;
            return root;
        }
    };