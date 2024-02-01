/* Daily Question: 2966. Divide Array Into Arrays With Max Difference
 * by Tyler Edwards | January 31st, 2024 
 * Code Credit: kreakEmp
 * You are given an integer array nums of size n and a positive integer k.
 * Divide the array into one or more arrays of size 3 satisfying the following conditions:
 * - Each element of nums should be in exactly one array.
 * - The difference between any two elements in one array is less than or equal to k.
 * Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them. */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 2] > k) {
                return {};
            }

            answer.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }

        return answer;
    }
};