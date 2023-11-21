/* Daily Question: 1814. Count Nice Pairs in an Array
 * by Tyler Edwards | November 20th, 2023 
 * You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. 
 * For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
 * - 0 <= i < j < nums.length
 * - nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
 * Return the number of nice pairs of indices. Since that number can be too large, return it modulo 10^9 + 7. */

class Solution {
public:
    const int MAX = 1000000007;
    int rev(int flip)
    {
        int flipped = 0;

        while(flip != 0)
        {
            flipped = flipped * 10 + flip % 10;
            flip /= 10;
        }

        return flipped;
    }

    int countNicePairs(vector<int>& nums) 
    {
        unordered_map<int, int> map;
        int n = nums.size(), answer = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = nums[i] - rev(nums[i]);
            map[temp]++;
            answer = (answer + map[temp] - 1) % MAX;
        }

        return answer % MAX;
    }
};