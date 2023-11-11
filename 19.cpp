/* LeetCode Day 17: N-th Tribonacci Number (Easy) 19/75 
 * by Tyler Edwards | November 10th, 2023 
 * Desc: The Tribonacci sequence Tn is defined as follows: 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * Given n, return the value of Tn. */

class Solution {
public:
    int tribonacci(int n) 
    {
        if (n == 0)
        {
            return 0;
        }

        if (n == 1 || n == 2)
        {
            return 1;
        }

        vector<int> tribonacci(n + 1);
        tribonacci[0] = 0;
        tribonacci[1] = 1;
        tribonacci[2] = 1;

        for (int i = 3; i < n + 1; i++)
        {
            tribonacci[i] = tribonacci[i - 1] + tribonacci[i - 2] + tribonacci[i - 3];
        }

        return tribonacci[n];
    }
};