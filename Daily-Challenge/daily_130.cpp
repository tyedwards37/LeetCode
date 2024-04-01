/* Daily Question: 58. Length of Last Word
 * by Tyler Edwards | March 31st, 2024 
 * Code Credit: jianchao-li
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only. */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0; // keeps track of the length of the last word 
        int tail = s.length() - 1; // variable to mark the end of the length of the string
        while (tail >= 0 && s[tail] == ' ') tail--; // removes any spaces that are at the end of string
        while (tail >= 0 && s[tail] != ' ') { // conditions for the loop 
            len++; // increase the length variable by one 
            tail--; // moves index checking if its a space back by one character
        }

        return len; // return the length of the last word 
    }
};