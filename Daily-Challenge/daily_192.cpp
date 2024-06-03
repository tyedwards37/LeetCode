/* Daily Question: 2486. Append Characters to String to Make Subsequence
 * by Tyler Edwards | June 2nd, 2024 
 * Code Credit: lancertech6
 * You are given two strings s and t consisting of only lowercase English letters.
 * Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
 * A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. */

class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0; // intialize an index integer for both strings
        int s_length = s.length(), t_length = t.length(); // intialize a length integer for bother strings
    
        while (s_index < s_length && t_index < t_length) { // loop while the index is lower than the size 
            if (s[s_index] == t[t_index]) { // check if the characters at the given indexes are the same 
                t_index++; // increment the t index
            }
            s_index++; // increment the s index
        }
    
        return t_length - t_index; // return the length of t minus the index
    }
};