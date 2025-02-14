/* Daily Question: 2981. Find Longest Special Substring That Occurs Thrice I
 * by Tyler Edwards | December 9th, 2024  
 * Code Credit: innocentCoder
 * You are given a string s that consists of lowercase English letters.
 * A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
 * Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
 * A substring is a contiguous non-empty sequence of characters within a string. */

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 1, r = n;

        if (!helper(s, n, l)) return -1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (helper(s, n, mid)) l = mid;
            else r = mid;
        }

        return l;
    }

private:
    bool helper(const string& s, int n, int x) {
        vector<int> cnt(26, 0);
        int p = 0;

        for (int i = 0; i < n; i++) {
            while (s[p] != s[i]) p++;
            if (i - p + 1 >= x) cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 2) return true;
        }

        return false;
    }
};