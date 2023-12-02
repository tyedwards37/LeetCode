/* LeetCode Day 37: Maximum Twin Sum of a Linked List (2130) (Medium) 40/75 
 * by Tyler Edwards | December 1st, 2023 
 * In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
 * - For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
 * The twin sum is defined as the sum of a node and its twin.
 * Given the head of a linked list with even length, return the maximum twin sum of the linked list. */

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
    int pairSum(ListNode* head) 
    {
        ListNode* slow = head; 
        ListNode* fast = head;
        int maxValue = 0;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* nextNode, *prevNode = NULL;
        while (slow)
        {
            nextNode = slow->next;
            slow->next = prevNode;
            prevNode = slow;
            slow = nextNode;
        }

        while(prevNode)
        {
            maxValue = max(maxValue, head->val + prevNode->val);
            prevNode = prevNode->next;
            head = head->next;
        }

        return maxValue;
    }
};