/* Daily Question: 1464. Maximum Product of Two Elements in an Array
 * by Tyler Edwards | December 11th, 2023 
 * Code Credit: suniti0804
 * Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1). */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        int n = paths.size();

        unordered_set<string> str;
        for (int i = 0; i < n; i++)
        {
            str.insert(paths[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (str.find(paths[i][1]) == str.end())
            {
                return paths[i][1];
            }
        }

        return "";
    }
};