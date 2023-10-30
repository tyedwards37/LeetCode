/* LeetCode Day 6: Is Subsequence (Easy) 7/75 
 * by Tyler Edwards | October 29th, 2023
 * Desc: Given two strings s and t, return true if s is a subsequence of t, or false otherwise. A subsequence of a string is a new string 
 * that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of 
 * the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not). */

class Solution 
{
public:
    #include <string> 

    bool isSubsequence(string s, string t) 
    {
        int sIndex = 0, tIndex = 0;
        
        while (tIndex <= t.size())
        {   
            if (s[sIndex] == t[tIndex])
            {
                sIndex++;
                tIndex++;
            }

            else
            {
                tIndex++;
            }

            if(sIndex >= s.size() || s == "")
            {
                return true;
            }

            if(tIndex == t.size())
            {
                break;
            }
        }

        return false;
    }
};