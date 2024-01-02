/* Daily Question: 2610. Convert an Array Into a 2D Array With Conditions
 * by Tyler Edwards | January 1st, 2024 (Happy New Year!)
 * Code Credit: lancertech6
 * You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
 * - The 2D array should contain only the elements of the array nums.
 * - Each row in the 2D array contains distinct integers.
 * - The number of rows in the 2D array should be minimal.
 * Return the resulting array. If there are multiple answers, return any of them. */

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
       vector<int> frequency(nums.size() + 1);

        vector<vector<int>> answer;
       for (int num : nums)
       {
           if (frequency[num] >= answer.size())
           {
               answer.push_back({});
           }

           answer[frequency[num]].push_back(num);
           frequency[num]++;
       }

       return answer;
    }
};