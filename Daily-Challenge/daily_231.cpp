/* Daily Question: 1717. Maximum Score From Removing Substrings
 * by Tyler Edwards | July 11th, 2024 
 * Code Credit: lee215
 * You are given a string s and two integers x and y. You can perform two types of operations any number of times.
 * - Remove substring "ab" and gain x points.
 *   - For example, when removing "ab" from "cabxbae" it becomes "cxbae". 
 * - Remove substring "ba" and gain y points.
 *   - For example, when removing "ba" from "cabxbae" it becomes "cabxe".
 * Return the maximum points you can gain after applying the above operations on s. */

class Solution {
    int remove(string &s, string r, int x) {
        int i = 0, ans = 0; // `i` is write pointer, `j` is read pointer. 
        for (int j = 0; j < s.size(); ++j) {
            s[i++] = s[j];
            if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) i -= 2, ans += x; // We keep removing pattern string `r` when `r` shows up in the end of written part.
        }
        s.resize(i);
        return ans;
    }
    
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if (x < y) swap(a, b), swap(x, y);
        return remove(s, a, x) + remove(s, b, y);
    }
};