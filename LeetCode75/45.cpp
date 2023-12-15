/* LeetCode Day 41: Binary Tree Right Side View (199) (Medium) 45/75 
 * Tyler Edwards | December 6th, 2023 
 * Code Credit: gavin5
 * Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom. */

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
    vector<int> answers;

    void recursion(TreeNode* node, int depth)
    {
      if(!node)
      {
        return;
      }

      if (answers.size() < depth)
      {
        answers.push_back(node->val);
      }

      recursion(node->right, depth + 1);
      recursion(node->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        recursion(root, 1);
        return answers;
    }
};
