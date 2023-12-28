/* Daily Question: 1531. String Compression II
 * by Tyler Edwards | December 27th, 2023 
 * Code Credit: plus2047
 * Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). 
 * For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".
 * Notice that in this problem, we are not adding '1' after single characters.
 * Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.
 * Find the minimum length of the run-length encoded version of s after deleting at most k characters. */

class Solution {
public:
    const static int N = 127;
    int dp[N][N];
    string str;
    int n;

    inline int xs(int x)
    {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }

    int solve(int left, int k)
    {
        if (k < 0)
        {
            return N;
        }

        if (left >= n || n - left <= k)
        {
            return 0;
        }

        int& answer = dp[left][k];
        if (answer != -1)
        {
            return answer;
        }
        answer = N;

        int cnt[26] = {0};

        for (int j = left, most = 0; j < n; j++)
        {
            most = max(most, ++cnt[str[j] - 'a']);
            answer = min(answer, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }

        return answer;
    }

    int getLengthOfOptimalCompression(string s, int k) 
    {
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};