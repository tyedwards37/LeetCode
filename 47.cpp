/* LeetCode Day 43: 450. Delete Node in a BST (Medium) 47/75 
 * Tyler Edwards | December 8th, 2023 
 * Code Credit: _LeetCoder25_
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 * Basically, the deletion can be divided into two stages:
 * 1. Search for a node to remove.
 * 2. If the node is found, delete the node. */

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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root)
        {
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }

            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }

            else
            {
                if (!root->left && !root->right)
                {
                    return NULL;
                }

                if (!root->left || !root->right)
                {
                    return root->left ? root->left : root->right;
                }

                TreeNode* temp = root->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }

                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }

        return root;
    }
};