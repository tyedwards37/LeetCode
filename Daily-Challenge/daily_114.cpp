/* Daily Question: 525. Contiguous Array
 * by Tyler Edwards | March 15th, 2024 
 * Code Credit: _LeetCoder25_
 * Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1. */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLen=0;
        unordered_map<int, int> seen{{0, -1}};
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]==1 ? 1 : -1;
            if(seen.count(sum)) maxLen = max(maxLen, i-seen[sum]);
            else seen[sum] = i;
        }
        return maxLen;
    }
};