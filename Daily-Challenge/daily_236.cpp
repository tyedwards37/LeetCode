/* Daily Question: 1110. Delete Nodes And Return Forest
 * by Tyler Edwards | July 16th, 2024 
 * Code Credit: lee215
 * Given the root of a binary tree, each node in the tree has a distinct value.
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
 * Return the roots of the trees in the remaining forest. You may return the result in any order. */

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
        vector<TreeNode*> result;
    set<int> to_delete_set;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        helper(root, result, to_delete_set, true);
        return result;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted) result.push_back(node);
        node->left = helper(node->left, result, to_delete_set, deleted);
        node->right =  helper(node->right, result, to_delete_set, deleted);
        return deleted ? NULL : node;
    }
};