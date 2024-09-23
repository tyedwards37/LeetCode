/* Daily Question: 2707. Extra Characters in a String
 * by Tyler Edwards | September 21st, 2024 
 * Code Credit: singhh_sidhantt
 * You are given a 0-indexed string s and a dictionary of words dictionary. 
 * You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. 
 * There may be some extra characters in s which are not present in any of the substrings. 
 * Return the minimum number of extra characters left over if you break up s optimally. */

class Solution {
public:
    int minExtraChar(const string &s, vector<string>& dict) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        
        return minExtraCharHelper(s, dict, 0);
    }
    
private:
    int dp[51]; // Initialize dp array to store memoization values

    int minExtraCharHelper(const string &s, vector<string>& dict, int i) {
        if (i == s.size())
            return 0;

        if (dp[i] == -1) {
            dp[i] = 1 + minExtraCharHelper(s, dict, i + 1); // Initialize with one extra character.

            for (const auto &w : dict) {
                if (s.compare(i, w.size(), w) == 0) {
                    dp[i] = min(dp[i], minExtraCharHelper(s, dict, i + w.size())); // Update if a word in the dictionary is found.
                }
            }
        }

        return dp[i]; // Return the minimum extra characters starting from position i.
    }
};