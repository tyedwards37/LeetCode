/* Daily Question: 3217. Delete Nodes From Linked List Present in Array
 * by Tyler Edwards | September 5th, 2024 
 * Code Credit: intelligent_660606
 * You are given an array of integers nums and the head of a linked list. 
 * Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums. */

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* newHead = temp;

        while(temp->next){
            if(st.count(temp->next->val)){
                ListNode* d = temp->next;
                temp->next = temp->next->next;
                delete(d);
            }
            else{
                temp = temp->next;
            }
        }
        return newHead->next;
    }
};