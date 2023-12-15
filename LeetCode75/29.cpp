/* LeetCode Day 27: Maximum Number of Vowels in a Substring of Given Length (1456) (Medium) 29/75 
 * by Tyler Edwards | November 20th, 2023 
 * Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'. */

class Solution {
public:
    bool isVowel(char c)
    {
        char t = tolower(c);
        return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
    }

    int maxVowels(string s, int k) 
    {
        int length = s.size();
        int currCount = 0, maxVowels = 0;

        for (int i = 0; i < length; i++)
        {
           if (i >= k && isVowel(s[i - k])) 
           {
               currCount--;
           }

           if (isVowel(s[i])) 
           {
               currCount++;
           }

           maxVowels = max(maxVowels, currCount);
        } 

        return maxVowels;
    }
};
