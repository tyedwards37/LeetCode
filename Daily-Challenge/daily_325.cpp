/* Daily Question: 2530. Maximal Score After Applying K Operations
 * by Tyler Edwards | October 13th, 2024 
 * Code Credit: netcan
 * You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
 * In one operation:
 * 1. choose an index i such that 0 <= i < nums.length,
 * 2. increase your score by nums[i], and
 * 3. replace nums[i] with ceil(nums[i] / 3).
 * Return the maximum possible score you can attain after applying exactly k operations.
 * The ceiling function ceil(val) is the least integer greater than or equal to val. */

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0; 
        priority_queue<int> pq(nums.begin(), nums.end()); 
        while (k--) {
            int val = pq.top(); pq.pop();
            ans += val; 
            pq.push((val+2)/3); 
        }
        return ans; 
    }
};