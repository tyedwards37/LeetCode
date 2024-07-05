/* Daily Question: 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
 * by Tyler Edwards | July 4th, 2024 (Happy 4th of July)
 * Code Credit: lancertech6
 * A critical point in a linked list is defined as either a local maxima or a local minima.
 * A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
 * A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
 * Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
 * Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points.
 * If there are fewer than two critical points, return [-1, -1]. */

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev=head;
        head=head->next;
        int i=1,mindist=INT_MAX,prev_i=INT_MIN,first_i=-1;
        while(head->next){
            if((prev->val < head->val and head->val > head->next->val) ||( prev->val > head->val and head->val < head->next->val)){
                if(prev_i!=INT_MIN) mindist=min(mindist,i-prev_i);
                if(first_i==-1) first_i=i;
                prev_i=i;
            }
            prev=head;
            head=head->next;
            i++;
        }
        if(mindist==INT_MAX) return {-1,-1};
        return {mindist,prev_i-first_i};
    }
};