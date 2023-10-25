/* LeetCode Day 1: Merge String Alternatively (Easy) 1/75 
 * by Tyler Edwards | October 24th, 2023
 * Desc: You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
 * If a string is longer than the other, append the additional letters onto the end of the merged string. Return the merged string. */


class Solution {
public:
    #include <string>
    
    string mergeAlternately(string word1, string word2) 
    {
        string merge = "";
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < word1.length() + word2.length(); i++)
        {
            if(count1 < word1.length())
            {
                merge += word1[count1];
                count1++;
            }

            if(count2 < word2.length())
            {
                merge += word2[count2];
                count2++;
            }
        }

        return merge;
    }
};