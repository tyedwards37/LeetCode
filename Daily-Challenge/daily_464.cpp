/* Daily Question: 1358. Number of Substrings Containing All Three Characters
 * by Tyler Edwards | March 10th, 2025 
 * Code Credit: lee
 * Given a string s consisting only of characters a, b and c. 
 * Return the number of substrings containing at least one occurrence of all these characters a, b and c. */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0},res = 0 , i = 0, n = s.length();
        for (int j = 0; j < n; ++j) {
            ++count[s[j] - 'a'];
            while (count[0] && count[1] && count[2])
                --count[s[i++] - 'a'];
            res += i;
        }
        return res;
    }
};