/* LeetCode Day 4: Reverse Voewls of a String (Easy) 5/75 
 * by Tyler Edwards | October 27th, 2023
 * Desc: Given a string s, reverse only all the vowels in the string and return it.
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once. */

#include <unordered_set>
    

class Solution {
public:
    #include <string>

    bool isVowel(char c)
    {
        static std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                                  'A', 'E', 'I', 'O', 'U'};
        return vowels.find(c) != vowels.end();
    }

    string reverseVowels(string s) 
    {
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right)
        {
            while(left < right && !isVowel(s[left]))
            {
                left++;
            }

            while(left < right && !isVowel(s[right]))
            {
                right--;
            }

            std::swap(s[left], s[right]);

            left++;
            right--;
        }
        
        return s;
    }
};
