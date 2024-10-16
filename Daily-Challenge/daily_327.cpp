/* Daily Question: 1405. Longest Happy String
 * by Tyler Edwards | October 15th, 2024 
 * Code Credit: votrubac
 * A string s is called happy if it satisfies the following conditions:
 * - s only contains the letters 'a', 'b', and 'c'.
 * - s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * - s contains at most a occurrences of the letter 'a'.
 * - s contains at most b occurrences of the letter 'b'.
 * - s contains at most c occurrences of the letter 'c'.
 * Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. 
 * If there is no such string, return the empty string "". 
 * A substring is a contiguous sequence of characters within a string. */

class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        if (b == 0)
            return string(min(2, a), aa);
        auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0; 
        return string(use_a, aa) +  string(use_b, bb) + 
            longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
    }
};