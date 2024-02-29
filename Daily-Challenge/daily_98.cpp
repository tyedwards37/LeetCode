/* Daily Question: 1609. Even Odd Tree
 * by Tyler Edwards | February 28th, 2024 
 * Code Credit: sahilChoudhary16
 * A binary tree is named Even-Odd if it meets the following conditions:
 * - The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
 * - For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
 * - For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
 * Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false. */

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
    unordered_map<int , int > m;

    bool dfs(TreeNode* root , int level ){
        if (root == NULL )  return true;
        if (level & 1){
            if ( root->val  &  1  )  return false; 
        }
        else if ( !(root->val & 1) ) return false; 
        
        if (m.find(level) != m.end() ){
            if (level & 1 ){
                if (m[level] <= root->val ) return false; // should be strictely strictly decreasing   
            }
            else if (m[level] >= root->val ) return false; // should be strictely strictly increasing  
        }
    
        m[level] =  root->val;
        return dfs(root->left , level + 1) && dfs(root->right, level +  1);
    }
    
    
public:
    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0 );
    }
};