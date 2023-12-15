/* LeetCode Day 36: Odd Even Linked List (328) (Medium) 39/75 
 * by Tyler Edwards | November 30th, 2023 
 * Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
 * The first node is considered odd, and the second node is even, and so on.
 * Note that the relative order inside both the even and odd groups should remain as it was in the input.
 * You must solve the problem in O(1) extra space complexity and O(n) time complexity. */

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;

        while (odd->next && even->next)
        {
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = even_start;
        return head;
    }
};
