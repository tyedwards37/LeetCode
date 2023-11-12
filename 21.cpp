/* LeetCode Day 19: Counting Bits (Easy) 21/75 
 * by Tyler Edwards | November 12th, 2023 
 * Desc: Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.*/

class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> bits(n);
        bits.push_back(0);
        if (n == 0)
        {
            return bits;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                bits[i] = bits[i / 2];
            }

            else
            {
                bits[i] = bits[i - 1] + 1;
            }
        }

        return bits;
    }
};