/* Daily Question: 2938. Separate Black and White Balls
 * by Tyler Edwards | October 14th, 2024 
 * Code Credit: prathamesh-003
 * There are n balls on a table, each ball has a color black or white.
 * You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.
 * In each step, you can choose two adjacent balls and swap them.
 * Return the minimum number of steps to group all the black balls to the right and all the white balls to the left. */

class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0, ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans += cnt;
            } else {
                cnt++;
            }
        }
        return ans;
    }
};