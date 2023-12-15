/* LeetCode Day 10: Find the Difference of Two Arrays (Easy) 12/75 
 * by Tyler Edwards | November 2nd, 2023 
 * Desc: Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
 * - answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
 * - answer[1] is a list of all distinct integers in nums2 which are not present in nums1. */

class Solution {
public:
    #include <vector>

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> answer;
        vector<int> unique1;
        vector<int> unique2;

        int count = 0;

        while (count < nums1.size())
        {
            bool unique = true;
            for (int check : nums2)
            {
                if (nums1[count] == check)
                {
                    unique = false;
                }
            }

            for (int check : unique1)
            {
                if (nums1[count] == check)
                {
                    unique = false;
                }
            }

            if(unique)
                {
                    unique1.push_back(nums1[count]);
                }
            count++;
        }

        answer.push_back(unique1);
        count = 0;

        while (count < nums2.size())
        {
            bool unique = true;
            for (int check : nums1)
            {
                if (nums2[count] == check)
                {
                    unique = false;
                }
            }

            for (int check : unique2)
            {
                if (nums2[count] == check)
                {
                    unique = false;
                }
            }

            if(unique)
                {
                    unique2.push_back(nums2[count]);
                }
            count++;
        }

        answer.push_back(unique2);
        return(answer);
    }
};
