/* Daily Question: 988. Smallest String Starting From Leaf
 * by Tyler Edwards | April 16th, 2024 
 * Code Credit: asylzhanbeats
 * You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
 * Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
 * As a reminder, any shorter prefix of a string is lexicographically smaller.
 * - For example, "ab" is lexicographically smaller than "aba".
 * A leaf of a node is a node that has no children. */

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
    string answer = "~"; // intializes a answer string to a default value of '~'
public:     
    void recure(TreeNode* root, string s){
            if (!root) return; // check if the root exists, which will end the recursive calls
            if (!root->left && !root->right){ // checks if the root is a leaf or not
                answer = min(answer,char(root->val+'a')+s); // sets the answer string to the minimum lexicographical value between its current value and teh charcater at that node
            }
            recure(root->left,char(root->val+'a')+s); // recursively call the recure function with the left child node and the answer string appeneded to the character value
            recure(root->right,char(root->val+'a')+s); // recursively call the recure function with the right child node and the answer string appeneded to the character value
}
    string smallestFromLeaf(TreeNode* root) {
        recure(root,""); // starts the recurseive call at the root of the tree with an empty string
        return answer; // returns the final answer string
    }
};