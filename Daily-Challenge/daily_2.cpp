/* Daily Question: 1846. Maximum Element After Decreasing and Rearranging
 * by Tyler Edwards | November 15th, 2023 
 * Desc: You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions: 
 * The value of the first element in arr must be 1. AND The absolute difference between any 2 adjacent elements must be less than or equal to 1. 
 * In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x. */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) <= 1 )
            {
                continue;
            }

            else
            {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};
