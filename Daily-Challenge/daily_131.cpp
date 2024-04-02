/* Daily Question: 205. Isomorphic Strings
 * by Tyler Edwards | April 1st, 2024 (april fools!)
 * Code Credit: grandyang
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t. 
 * All occurrences of a character must be replaced with another character while preserving the order of characters. 
 * No two characters may map to the same character, but a character may map to itself. */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size(); // two arrays for ASCII of size 256 and a variable for the size of the string
        for (int i = 0; i < n; ++i) { // iterate through the length of the string
            if (m1[s[i]] != m2[t[i]]) return false; // checks if the amount of time that character has been called matches in both s and t and if it isn't return false 
            m1[s[i]] = i + 1; // move to the next character in the string s 
            m2[t[i]] = i + 1; // move to teh next character in the string t
        }
        return true; // if it hasn't exited return true
    }
};