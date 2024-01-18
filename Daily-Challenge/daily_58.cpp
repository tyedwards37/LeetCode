/* Daily Question: 70. Climbing Stairs
 * by Tyler Edwards | January 18th, 2024 
 * Code Credit: rahulvarma5297
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int prev = 1, curr = 1;

        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }

        return curr;
    }
};