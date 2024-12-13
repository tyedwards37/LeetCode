/* Daily Question: 2593. Find Score of an Array After Marking All Elements
 * by Tyler Edwards | December 12nd, 2024  
 * Code Credit: Kishan Kumar Patel
 * You are given an array nums consisting of positive integers.
 * Starting with score = 0, apply the following algorithm:
 * - Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
 * - Add the value of the chosen integer to score.
 * - Mark the chosen element and its two adjacent elements if they exist.
 * - Repeat until all the array elements are marked.
 * Return the score you get after applying the above algorithm. */

 class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        set<pair<int, int>> st;
        for(int i = 0; i < nums.size(); ++i){ st.insert({nums[i], i}); }
        for(auto s: st){
            if(nums[s.second] == 0) continue;
            score += s.first;
            nums[s.second] = 0;
            if(s.second - 1 >= 0) nums[s.second - 1] = 0;
            if(s.second + 1 < nums.size()) nums[s.second + 1] = 0;
        }
        return score;
    }
};