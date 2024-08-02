/* Daily Question: 2134. Minimum Swaps to Group All 1's Together II
 * by Tyler Edwards | August 1st, 2024 
 * Code Credit: tojuna
 * A swap is defined as taking two distinct positions in an array and swapping the values in them.
 * A circular array is defined as an array where we consider the first element and the last element to be adjacent.
 * Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location. */

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0, x = 0, onesInWindow = 0, i = 0, n = nums.size();
        ones = count(begin(nums), end(nums), 1);
        vector<int> nums2(n * 2);
        for (i = 0; i < n * 2; i++)
            nums2[i] = nums[i % n];
        for (i = 0; i < n * 2; i++) {
            if (i >= ones && nums2[i - ones] == 1) x--;
            if (nums2[i] == 1) x++;
            onesInWindow = max(x, onesInWindow);
        }
        return ones - onesInWindow;
    }
};