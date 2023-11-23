/* Daily Question: 1424. Diagonla Traverse II
 * by Tyler Edwards | November 22nd, 2023 
 * A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. 
 * More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i. 
 * You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
 * Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise. */


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> check;
        int lSize = l.size();

        for (auto i = 0, j = 0; i < lSize; i++)
        {
            vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
            sort(begin(n), end(n));
            
            int nSize = n.size();

            for (j = 2; j < nSize; j++)
            {
                if (n[j] - n[j - 1] != n[1] - n[0])
                {
                    break;
                }
            }

            check.push_back(j == nSize);
        }

        return check;
    }
};