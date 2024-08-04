/* Daily Question: 1508. Range Sum of Sorted Subarray Sums
 * by Tyler Edwards | August 3rd, 2024 
 * Code Credit: milu
 * You are given the array nums consisting of n positive integers. 
 * You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
 * Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7. */

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
        for (int i=0; i<n; i++)
            mqueue.push({nums[i], i+1});

        int ans = 0, mod = 1e9+7;
        for (int i=1; i<=right; i++) {
            auto p = mqueue.top();
            mqueue.pop();
            if (i >= left)
                ans = (ans + p.first) % mod;
            if (p.second < n) {
                p.first += nums[p.second++];
                mqueue.push(p);
            }
        }
        return ans;
    }
};