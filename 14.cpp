/* LeetCode Day 12: Unique Number of Occurrences (Easy) 14/75 
 * by Tyler Edwards | November 5th, 2023 
 * Desc: Given the head of a singly linked list, reverse the list, and return the reversed list. */

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *next, *prev = NULL;

        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next; 
        }

        return prev;
    }


};