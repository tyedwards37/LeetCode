/* Daily Question: 91. Decode Ways
 * by Tyler Edwards | December 24th, 2023 (Santa is Coming!)
 * Code Credit: hiepit
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:
 * - 'A' = "1"
 * - 'B' = "2"
 * ...
 * - 'Z' = "26"
 * To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). 
 * For example, "11106" can be mapped into:
 * - "AAJF" with the grouping (1 1 10 6)
 * - "KJF" with the grouping (11 10 6)
 *Given a string s containing only digits, return the number of ways to decode it. */

class Solution { 
public:
    int memo[100] = {};
    int numDecodings(const string& s) 
    {
        return dp(s, 0);
    }

    int dp(const string& s, int i) 
    {
        if (i == s.size()) return 1;
        if (memo[i] != 0) return memo[i];

        int ans = 0;

        if (s[i] != '0')
            ans += dp(s, i+1);

        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) 
            ans += dp(s, i+2);
            
        return memo[i] = ans;
    }
};