/* Daily Question: 2583. Kth Largest Sum in a Binary Tree
 * by Tyler Edwards | October 21st, 2024 
 * Code Credit: vidit987
 * You are given the root of a binary tree and a positive integer k.
 * The level sum in the tree is the sum of the values of the nodes that are on the same level.
 * Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
 * Note that two nodes are on the same level if they have the same distance from the root. */

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<int>>v;
        int i,n;
        if(!root)return -1;        
        queue<TreeNode*>q;
        priority_queue<long long>pq;
        q.push(root);
        while(!q.empty()){
            n=q.size();
            long long sum=0;
            for(i=0;i<n;i++){
                TreeNode* x = q.front();
                q.pop();
                sum+=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            pq.push(sum);
        }
        if(pq.size()<k)return -1;
        k=k-1;
        while(k--)pq.pop();
        return pq.top();
    }
};