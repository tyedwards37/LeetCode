/* Daily Question: 206. Reverse Linked List
 * by Tyler Edwards | March 20th, 2024 
 * Code Credit: Ajna
 * Given the head of a singly linked list, reverse the list, and return the reversed list. */

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
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevnode = NULL; // initializes two NULL node pointers

        while (head) { // while the head node isn't NULL
            nextNode = head->next; // sets the next pointer to the node after the current 
            head->next = prevNode; // sets the node after current to the previous pointer
            prevNode = head; // the previous pointer is set to the current node 
            head = nextNode; // the head node is set to the next pointer
        }

        return prev;
    }
};