/* Daily Question: 664. Strange Printer
 * by Tyler Edwards | August 20th, 2024 
 * Code Credit: suyalneeraj09
 * There is a strange printer with the following two special properties:
 * - The printer can only print a sequence of the same character each time.
 * - At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
 * Given a string s, return the minimum number of turns the printer needed to print it. */

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return Util(0, n - 1, s, dp);
    }

    int Util(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        char firstLetter = s[i];
        // If the current character is not repeated in the rest of the string
        int answer = 1 + Util(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++) {
            // If repeated then update the answer
            if (s[k] == firstLetter) {
                // Splitting from i -> k - 1 (remove the last character)
                // and from k + 1 -> j             
                int betterAnswer = Util(i, k - 1, s, dp) + Util(k + 1, j, s, dp);
                answer = min(answer, betterAnswer);
            }
        }
        return dp[i][j] = answer;
    }
};