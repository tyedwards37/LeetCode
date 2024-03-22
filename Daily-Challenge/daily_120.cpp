/* Daily Question: 234. Palindrome Linked List
 * by Tyler Edwards | March 21st, 2024 
 * Code Credit: sgallivan
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/

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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp; // intializes four Node pointers to the head of the list: a slow, fast, prev, and temp
        while (fast && fast->next) // while fast and the node after fast is not NULL, loop this code
            slow = slow->next, fast = fast->next->next; // have the slow pointer move to the next node and the fast pointer move by two nodes
        prev = slow, slow = slow->next, prev->next = NULL; // set the prev pointer to the node slow is pointing at, have slow point at the node after the current slow, set the next of the prev pointer to NULL
        while (slow) // loop while slow isn't NULL
            temp = slow->next, slow->next = prev, prev = slow, slow = temp; // set the temp pointer to the node after slow, set the node after slow to prev, set prev to slow, and set slow to temp
        fast = head, slow = prev; // fast becomes the top of the list and slow is set to the position of prev
        while (slow) // loop while slow isn't NULL
            if (fast->val != slow->val) return false; // if the value of fast and slow aren't equal return false
            else fast = fast->next, slow = slow->next; // if they are equal set fast to the next node and slow to the next node (which will be going in reverse)
        return true; // if it makes it through the loop without being false it must be true, return true
    }
};