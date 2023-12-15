/* Daily Question: 1287. Element Appearing More Than 25% In Sorted Array
 * by Tyler Edwards | December 10th, 2023 
 * Code Credit: MrJia1997
 * Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer. */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int amount = arr.size();

        vector<int> candidates = {arr[amount/4], arr[amount/2], arr[amount*3/4]};

        for (auto cand : candidates)
        {
            auto start = lower_bound(arr.begin(), arr.end(), cand);
            auto end = upper_bound(arr.begin(), arr.end(), cand);

            if (4 * (distance(start, end)) > amount)
            {
                return cand;
            }
        }

        return -1;
    }
};
