/* Daily Question: 725. Split Linked List in Parts
 * by Tyler Edwards | September 7th, 2024 (First time getting COVID)
 * Code Credit: alexander
 * Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
 * The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
 * The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later. 
 * Return an array of the k parts. */

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;
        int n = len / k, r = len % k; // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};