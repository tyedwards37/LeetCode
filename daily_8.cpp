/* Daily Question: 1424. Diagonla Traverse II
 * by Tyler Edwards | November 21st, 2023 
 * Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images. */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        int m = nums.size(), maxSum = 0, size = 0, index = 0;
        vector<vector<int>> map(100001);

        for (int i = 0; i < m; i++)
        {
            size += nums[i].size();

            for (int j = 0; j < nums[i].size(); j++)
            {
                int sum = i + j;
                map[sum].push_back(nums[i][j]);
                maxSum = max(maxSum, sum);
            }
        }

        vector<int> res(size);
        for (int i = 0; i <= maxSum; i++)
        {
            vector<int>& current = map[i];
            for (int j = current.size() - 1; j >= 0; j--)
            {
                res[index++] = current[j];
            }
        }

        return res;
    }
};