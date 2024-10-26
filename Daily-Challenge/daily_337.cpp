/* Daily Question: 2458. Height of Binary Tree After Subtree Removal Queries
 * by Tyler Edwards | October 25th, 2024 
 * Code Credit: lee215
 * You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
 * You have to perform m independent queries on the tree where in the ith query you do the following:
 * - Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
 * Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
 * Note:
 * - The queries are independent, so the tree returns to its initial state after each query.
 * - The height of a tree is the number of edges in the longest simple path from the root to some node in the tree. */

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
    int preh[100001], posth[100001], maxh;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxh = 0; pre(root, 0);
        maxh = 0; post(root, 0);
        vector<int> res;
        for (int q : queries)
            res.push_back(max(preh[q], posth[q]));
        return res;
    }

    void pre(TreeNode* root, int h) {
        if (!root) return;
        preh[root->val] = maxh;
        maxh = max(maxh, h);
        pre(root->left, h + 1);
        pre(root->right, h + 1);
    }

    void post(TreeNode* root, int h) {
        if (!root) return;
        posth[root->val] = maxh;
        maxh = max(maxh, h);
        post(root->right, h + 1);
        post(root->left, h + 1);
    }
};