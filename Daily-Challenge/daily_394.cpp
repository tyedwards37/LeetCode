/* Daily Question: 2471. Minimum Number of Operations to Sort a Binary Tree by Level
 * by Tyler Edwards | December 21st, 2024  
 * Code Credit: Kishan Kumar Patel
 * You are given the root of a binary tree with unique values.
 * In one operation, you can choose any two nodes at the same level and swap their values.
 * Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
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
class Solution {
public:
    int countSwap(vector<int>& t){
        int count = 0;
        map<int,int> mp;
        vector<int> u;
        for(int i = 0; i < t.size(); ++i){
            mp[t[i]] = i;
            u.push_back(t[i]);
        }
        sort(u.begin(), u.end());
        for(int i = 0; i < t.size(); ++i){
            if(t[i] != u[i] ){  // if not at correct place update the values in map and t array
                t[mp[u[i]]] = t[i];
                mp[t[i]] = mp[u[i]];
                mp[u[i]] = i;
                t[i] = u[i];
                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            while(n--){
                TreeNode* node = q.front();
                t.push_back(node->val);
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            for(auto c: t) cout<<c<<" "; cout<<endl;
            ans += countSwap(t);
        }
        return ans;
    }
};