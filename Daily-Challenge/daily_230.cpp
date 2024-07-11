/* Daily Question: 1190. Reverse Substrings Between Each Pair of Parentheses
 * by Tyler Edwards | July 10th, 2024 
 * Code Credit: lee215
 * You are given a string s that consists of lower case English letters and brackets.
 * Reverse the strings in each pair of matching parentheses, starting from the innermost one.
 * Your result should not contain any brackets. */

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> opened, pair(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                opened.push_back(i);
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;
            else
                res += s[i];
        }
        return res;
    }
};