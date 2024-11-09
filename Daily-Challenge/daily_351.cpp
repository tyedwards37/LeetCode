/* Daily Question: 3133. Minimum Array End
 * by Tyler Edwards | November 8th, 2024  
 * Code Credit: lee
 * You are given two integers n and x. 
 * You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.
 * Return the minimum possible value of nums[n - 1]. */

class Solution {
public:
    long long minEnd(int n, int x) {
        long long a = x;
        while (--n)
            a = (a + 1) | x;
        return a;
    }
};