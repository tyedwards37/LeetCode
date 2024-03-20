/* Daily Question: 1669. Merge In Between Linked Lists
 * by Tyler Edwards | March 19th, 2024 
 * Code Credit: Righley (from here on out I am going to comment along my understanding of each step of the solution)
 * You are given two linked lists: list1 and list2 of sizes n and m respectively.
 * Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
 * The blue edges and nodes in the following figure indicate the result: */

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int jump1 = 1; // intiates a variable to iterate through for all of list 1 
        ListNode *temp1 = list1; // sets the head of first list to a temp Node 
        while (jump1 < a){ // loops through the list until the temp Node is at the ath Node in list 1
            temp1 = temp1->next;
            jump1++;
        }                               
        
		jump1 = 1; // sets iterate value back to 1
        ListNode *temp2 = list1; // sets the head of list 2 to a second temp Node 
        while(jump1 <= b){ // loops through the list until the temp Node is at the bth Node in list 2
            temp2 = temp2->next;
            jump1++;
        }                              
        
		ListNode *temp3 = list2; // creates a new temp Node that is equal to the bth node of list 2
        while(temp3->next != NULL){ // loops through list2 until it reaches the end of the list,
            temp3 = temp3->next; // sets the third temp Node to the final (tail) node in list 2 
        }                               
        
		temp1->next = list2; // sets the next pointer of the temp node containing the ath node of list 1 to the head of list 2     
		temp3->next = temp2->next; // sets the next pointer of the temp node containing the tail of list 2 to the bth node
		return list1; // returns the original list with the adjustments                    
    }
};