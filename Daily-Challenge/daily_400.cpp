/* Daily Question: 1639. Number of Ways to Form a Target String Given a Dictionary
 * by Tyler Edwards | December 28th, 2024 
 * Code Credit: lee
 * You are given a list of strings of the same length words and a string target.
 * Your task is to form target using the given words under the following rules:
 * - target should be formed from left to right.
 * - To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
 * - Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. 
     In other words, all characters to the left of or at index k become unusuable for every string. 
 * - Repeat the process until you form the string target.
 * Notice that you can use multiple characters from the same string in words provided the conditions above are met. 
 * Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7. */

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.length(), mod = 1e9 + 7;
        vector<long> res(n + 1);
        res[0] = 1;
        for (int i = 0; i < words[0].length(); ++i) {
            vector<int> count(26);
            for (auto& w : words)
                count[w[i] - 'a']++;
            for (int j = n - 1; j >= 0; --j) {
                res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
            }
        }
        return res[n] % mod;
    }
};