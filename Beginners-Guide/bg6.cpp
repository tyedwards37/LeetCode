/* LeetCode Beginner's Guide: 383. Ransom Note (6/6)
 * by Tyler Edwards | January 14th, 2024 
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote. */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int numOfLetters[26] = {0};

        for (char ch : magazine) {
            numOfLetters[ch - 'a']++;
        }

        for (char ch : ransomNote) {
            numOfLetters[ch - 'a']--;
        }

        for (int i : numOfLetters) {
            if (i < 0) {
                return false;
            }
        }

        return true;
    }
};