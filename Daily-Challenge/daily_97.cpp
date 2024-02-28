/* Daily Question: 513. Find Bottom Left Tree Value
 * by Tyler Edwards | February 27th, 2024 
 * Code Credit: steffi_keran
 * Given the root of a binary tree, return the leftmost value in the last row of the tree. */

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root=q.front(); // get the value before pop coz pop will not return anyy val
            q.pop();
            if (root->right) {
                q.push(root->right);
            }
            if(root->left) q.push(root->left);
        }
        return root->val;
        
    }
};