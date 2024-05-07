/* Daily Question: 2816. Double a Number Represented as a Linked List
 * by Tyler Edwards | May 6th, 2024 (finals grind super tired sorry) 
 * Code Credit: lee215
 * You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
 * Return the head of the linked list after doubling it. */

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
        ListNode* doubleIt(ListNode* head) {
        if (head->val > 4)
            head = new ListNode(0, head);
        for(ListNode* node = head; node; node = node->next) {
            node->val = (node->val * 2) % 10;
            if (node->next && node->next->val > 4)
                node->val++;
        }
        return head;
    }
};