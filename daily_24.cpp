/* Daily Question: 606. Construct String from Binary Tree
 * by Tyler Edwards | December 7th, 2023 
 * Code Credit: prantik0128
 * Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.
 * Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree. */

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
    string tree2str(TreeNode* root) 
    {
        string answer = to_string(root->val);

        if (root->left)
        {
            answer += "(" + tree2str(root->left) + ")";
        }

        if (root->right)
        {
            if (!root->left)
            {
                answer += "()";
            }
            answer += "(" + tree2str(root->right) + ")";
        }

        return answer;
    }
};