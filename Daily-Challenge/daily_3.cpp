/* Daily Question: 1980. Find Unique Binary String
 * by Tyler Edwards | November 16th, 2023 
 * Desc: Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. 
 * If there are multiple answers, you may return any of them. */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
        string answer = "";

        for (int i = 0; i < n; i++)
        {
            answer += nums[i][i] == '0' ? '1' : '0';
        }

        return answer;
    }
};
