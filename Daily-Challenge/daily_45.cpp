/* Daily Question: 2870. Minimum Number of Operations to Make Array Empty
 * by Tyler Edwards | January 3rd, 2024 
 * Code Credit: MarkSPhilip31
 * You are given a 0-indexed array nums consisting of positive integers.
 * There are two types of operations that you can apply on the array any number of times:
 * - Choose two elements with equal values and delete them from the array.
 * - Choose three elements with equal values and delete them from the array.
 * Return the minimum number of operations required to make the array empty, or -1 if it is not possible. */

class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for (auto a: nums)
        {
            mp[a]++;
        }

        int count = 0;
        for (auto a: mp)
        {
            int t = a.second;
            if (t == 1)
            {
                return -1;
            }

            count += t/3;

            if (t % 3)
            {
                count++;
            }
        }

        return count;
    }
};