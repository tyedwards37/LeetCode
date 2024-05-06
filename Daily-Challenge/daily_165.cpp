/* Daily Question: 2487. Remove Nodes From Linked List
 * by Tyler Edwards | May 5th, 2024  
 * Code Credit: lee215
 * You are given the head of a linked list.
 * Remove every node which has a node with a greater value anywhere to the right side of it.
 * Return the head of the modified linked list. */

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

class Solution {
public:
        ListNode* removeNodes(ListNode* head) {
            if (!head) return NULL; // checks if the node is NULL and stops recursion
            head->next = removeNodes(head->next); // calls the function recursively for the next node and sets the current node's next t owhatever the resul tis
            return head->next && head->val < head->next->val ?  head->next : head; // if the the node exists and its value is less than the next value then return the next node, if not return the current node
    }
};
