/* Daily Question: 1608. Special Array With X Elements Greater Than or Equal X
 * by Tyler Edwards | May 26th, 2024 (Mom's Birthday)
 * Code Credit: vkg001
 * You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
 * Notice that x does not have to be an element in nums.
 * Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique. */

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ans = count(nums, mid);

            if (ans == mid) return mid;
            else if (ans > mid) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }
    int count(vector<int>& nums, int target) {
        int ans = 0;
        for (int num : nums) {
            if (num >= target) ans++;
        }
        return ans;
    }
};