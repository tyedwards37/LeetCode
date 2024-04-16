/* Daily Question: 623. Add One Row to Tree
 * by Tyler Edwards | April 15th, 2024 
 * Code Credit: 
 * Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
 * Note that the root node is at depth 1.
 * The adding rule is:
 * - Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
 * - cur's original left subtree should be the left subtree of the new left subtree root. 
 * - cur's original right subtree should be the right subtree of the new right subtree root. 
 * - If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree. */

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) { // checks if the depth is 1, which meanas the new layer is going to be the root
            TreeNode* newNode = new TreeNode(val); // creates a singular new node
            newNode -> left = root; // makes the new node the root of the current tree
            return newNode; // return the new tree
        }
        
        queue<TreeNode*> q; // intialize a queue 
        q.push(root); // push the root of the tree to the queue
        int count = 0; // intialize a count variable 
        
        while(!q.empty()) { // checks if the queue is empty
            // since we have to add values on all of the nodes
            // present at that level, so take out the size
            int n = q.size(); // intialize a variable for the size of the queue
            
            count++; // increment the count variable
            while(n--){ // loop and decrement the n variable each time
                TreeNode* curr = q.front(); // take out current node
                q.pop(); // pop it from queue
                
                // if we not reach till our required level
                // so we have to do nothing, simply push into queue
                if(count != depth - 1) { // check if the wanted depth has not been reached 
                    if(curr -> left) q.push(curr -> left); // push and go another level deeper on the left side
                    if(curr -> right) q.push(curr -> right); // push and go another level deeper on the right side
                }
                else { // reached the target level
                    TreeNode* newNode = new TreeNode(val); // make a new node to add
                    newNode -> left = curr -> left; // first put left of curr to newNode
                    curr -> left = newNode;  // now curr of left becomes newNode
                    
                    TreeNode* newNode2 = new TreeNode(val); // make a new node to add
                    newNode2 -> right = curr -> right; // first put right of curr to newNode
                    curr -> right = newNode2; // now curr of right becomes newNode
                }
            }
        }

        return root; // finally return the new tree
    }
};