/* Daily Question: 3066. Minimum Operations to Exceed Threshold Value II
 * by Tyler Edwards | February 12th, 2025 
 * Code Credit: Capt Spaulding
 * You are given a 0-indexed integer array nums, and an integer k.
 * In one operation, you will:
 * - Take the two smallest integers x and y in nums.
 * - Remove x and y from nums.
 * - Add min(x, y) * 2 + max(x, y) anywhere in the array.
 * Note that you can only apply the described operation if nums contains at least two elements.
 * Return the minimum number of operations needed so that all elements of the array are greater than or equal to k. */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int ans = 0;
        
        while (minHeap.top() < k) {
            if (minHeap.size() < 2) return -1; // Impossible to proceed

            long long num1 = minHeap.top(); minHeap.pop();
            long long num2 = minHeap.top(); minHeap.pop();
            
            long long newValue = 2 * num1 + num2;  // Prevent overflow
            minHeap.push(newValue);
            ans++; }
        
        return ans;}};