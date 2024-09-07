/* Daily Question: 1367. Linked List in Binary Tree
 * by Tyler Edwards | September 6th, 2024 
 * Code Credit: intelligent_660606
 * Given a binary tree root and a linked list with head as the first node. 
 * Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False. 
 * In this context downward path means a path that starts at some node and goes downwards. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool findSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        return head->val == root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right));
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return findSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};