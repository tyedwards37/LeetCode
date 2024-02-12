/* Daily Question: 169. Majority Element
 * by Tyler Edwards | February 11th, 2024 (Winning the Super Bowl with the power of love)
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array. */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num : nums) {
            m[num]++;
            if (m[num] > nums.size() / 2) return num;
        }
        return 0;
    }
};