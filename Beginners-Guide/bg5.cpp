/* LeetCode Beginner's Guide: 876. Middle of the Linked List (5/6)
 * by Tyler Edwards | January 14th, 2024 
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node. */

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
    int count = 0;
    
    void countNodes(ListNode* node) {
        if (!node) {
            return;
        }

        count++;
        countNodes(node->next);
    }

    ListNode* middleNode(ListNode* head) {
        countNodes(head);
        int middle;

        if (count % 2 == 0) {
            middle = count / 2;
        }

        else {
            middle = (count / 2) + 1;
        }

        ListNode* answer = head;
        for (int i = middle; i < count; i++) {
            answer = answer->next;
        }

        return answer;
    }
};