/* Daily Question: 1910. Remove All Occurrences of a Substring
 * by Tyler Edwards | February 10th, 2025 
 * Code Credit: Samyak Uttam
 * Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
 * - Find the leftmost occurrence of the substring part and remove it from s.
 * Return s after removing all occurrences of part.
 * A substring is a contiguous sequence of characters in a string. */

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int n = s.size(), m = part.size(), i, j;
        for (i = 0, j = 0; i < n; i++) {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }
};