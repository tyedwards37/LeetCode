/* Daily Question: 2415. Reverse Odd Levels of Binary Tree
 * by Tyler Edwards | December 19th, 2024  
 * Code Credit: Yash Sharma
 * Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
 * - For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
 * Return the root of the reversed tree.
 * A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
 * The level of a node is the number of edges along the path between it and the root node. */

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
 
class Solution 
{
public:
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root) return root;
        
        queue<TreeNode*> q;
        vector<int> values;
        q.push(root);
        int level=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front(); q.pop();
                
                if(level%2)
                    node->val = values[sz-i-1];
                
                if(node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right) 
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                
            }
            values = temp;
            level++;
        }
        return root;
            
        
    }
};