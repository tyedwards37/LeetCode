/* Daily Question: 387. First Unique Character in a String
 * by Tyler Edwards | February 4th, 2024 
 * Code Credit: dr_pro
 * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1. */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;

        for (char& c : s) {
            m[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) return i;
        }

        return -1;
    }
};