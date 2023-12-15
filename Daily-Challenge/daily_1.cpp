/* Daily Question: 1930. Unique Length-3 Palindromic Subsequences
 * by Tyler Edwards | November 14th, 2023 
 * Desc: Given a string s, return the number of unique palindromes of length three that are a subsequence of s. */

class Solution {
public:
    int countPalindromicSubsequence(string input) 
    {
        vector<int> minFrequency(26, INT_MAX);
        vector<int> maxFrequency(26, INT_MIN);

        for (int i = 0; i < input.size(); i++)
        {
            int charIndex = input[i] - 'a';
            minFrequency[charIndex] = min(minFrequency[charIndex], i);
            maxFrequency[charIndex] = max(maxFrequency[charIndex], i);
        }

        int unique = 0;

        for (int index = 0; index < 26; index++)
        {
            if (minFrequency[index] == INT_MAX || maxFrequency[index] == INT_MIN)
            {
                continue;
            }

            unordered_set<char> uniqueBetween;

            for (int i = minFrequency[index] + 1; i < maxFrequency[index]; i++)
            {
                uniqueBetween.insert(input[i]);
            }

            unique += uniqueBetween.size();
        }

        return unique;
    }
};
