/* Daily Question: 2807. Insert Greatest Common Divisors in Linked List
 * by Tyler Edwards | September 9th, 2024 
 * Code Credit: abhay5349singh
 * Given the head of a linked list head, in which each node contains an integer value.
 * Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
 * Return the linked list after insertion.
 * The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers. */

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
    
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *p = head;
        while(p->next){
            ListNode* node = new ListNode(gcd(p->val, p->next->val));
            
			// storing originally next pointer in list
            ListNode *on = p->next; 
			
			// inserting node in between
            p->next = node; 
            node->next = on;
			
			// moving to next node in original list
            p=on;
        }
        
        return head;
    }
};