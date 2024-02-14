/* Daily Question: 2149. Rearrange Array Elements by Sign
 * by Tyler Edwards | February 13th, 2024 
 * Code Credit: its_vishal_7575
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
 * You should rearrange the elements of nums such that the modified array follows the given conditions:
 * 1. Every consecutive pair of integers have opposite signs.
 * 2. For all integers with the same sign, the order in which they were present in nums is preserved.
 * 3. The rearranged array begins with a positive integer.
 * Return the modified array after rearranging the elements to satisfy the aforementioned conditions. */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int positiveElementIndex = 0, negativeElementIndex = 1;

        for(auto num : nums){
            if(num > 0){
                ans[positiveElementIndex] = num;
                positiveElementIndex += 2;
            }
            else if(num < 0){
                ans[negativeElementIndex] = num;
                negativeElementIndex += 2;
            }
        }
        return ans;
    }
};