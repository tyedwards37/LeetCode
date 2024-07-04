/* Daily Question: 2181. Merge Nodes in Between Zeros
 * by Tyler Edwards | July 3rs, 2024
 * Code Credit: lancertech6
 * You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
 * For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next; // create a plcaeholder node that comes after the head 
        ListNode* nextSum = modify; // create another node to hold the sum of the current set of values

        while (nextSum != nullptr) { // stop the loop if the nextSum reaches the end of the linked list
            int sum = 0; //intialize an integer that holds the sum 
            while (nextSum->val != 0) { // loop while the value of the current node isn't 0
                sum += nextSum->val; // adds the value of the current node to the sum
                nextSum = nextSum->next; // sets the nextSum node to the next node in the linked list
            }

            modify->val = sum; // set the value of the modify node to the sum of the linked list before the zero
            nextSum = nextSum->next; // sets the nextSum node to the next node in the linked list
            modify->next = nextSum; // set modify's next node to the nextSum, which is the value after the zero
            modify = modify->next; // set the modify node to the next node in the linked list
        }
        return head->next; // skips the initial 0 node and returns the linked list
    }
};