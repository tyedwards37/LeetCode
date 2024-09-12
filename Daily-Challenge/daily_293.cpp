/* Daily Question: 1684. Count the Number of Consistent Strings
 * by Tyler Edwards | September 10th, 2024 
 * Code Credit: Ajna
 * You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
 * Return the number of consistent strings in the array words. */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // support variable
        int res = words.size();
        bool alpha[26] = {};
        // populating alpha
        for (char c: allowed) alpha[c - 'a'] = true;
        // parsing all the words to see if each character is in alpha
        for (string word: words) {
            // in case we find an unallowed character, we decrease res and break
            for (char c: word) if (!alpha[c - 'a']) {
                res--;
                break;
            }
        }
        return res;
    }
};