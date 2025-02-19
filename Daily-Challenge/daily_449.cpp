/* Daily Question: 1415. The k-th Lexicographical String of All Happy Strings of Length n
 * by Tyler Edwards | February 18th, 2025 
 * Code Credit: Vlad
 * A happy string is a string that:
 * - consists only of letters of the set ['a', 'b', 'c'].
 * - s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
 * For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
 * Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
 * Return the kth string of this list or return an empty string if there are less than k happy strings of length n. */

class Solution {
public:
    string getHappyString(int n, int &k, int p = 0, char last_ch = 0) {
        if (p == n)
            --k;
        else
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                if (ch != last_ch) {
                    auto res = getHappyString(n, k, p + 1, ch);
                    if (k == 0)
                        return string(1, ch) + res;
                }
            }
        return "";
    }
};