/* Daily Question: 935. Knight Dialer
 * by Tyler Edwards | November 26th, 2023 
 * The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). 
 * The possible movements of chess knight are shown in this diagaram:
 * We have a chess knight and a phone pad, the knight can only stand on a numeric cell (i.e. blue cell). 
 * Given an integer n, return how many distinct phone numbers of length n we can dial.
 * You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps. 
 * As the answer may be very large, return the answer modulo 10^9 + 7.*/

class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> MOVES = {
    {4, 6},
    {8, 6},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
    };

    int cache[5001][10];

    int knightDialer(int n) 
    {
        vector<int> nextNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        return knightDialer(n, nextNumbers);
    }

    int knightDialer(int remaining, vector<int>& nextNumbers) 
    {
        if (remaining == 1)
        {
            return nextNumbers.size();
        }

        int count = 0;
        for (int nextNumber : nextNumbers) 
        {
            int cur = cache[remaining][nextNumber];

            if (cur == 0) 
            {
                cur = knightDialer(remaining - 1, MOVES[nextNumber]);
                cache[remaining][nextNumber] = cur;
            }

            count += cur;
            count %= MOD;
        }

        return count;
    }
};