/* LeetCode Day 21: Reverse Words in a String (Medium) 23/75 
 * by Tyler Edwards | November 14th, 2023 
 * Desc: Given an input string s, reverse the order of the words. */

class Solution {
public:
    string reverseWords(string s) 
    {
        if (s.size() == 0)
        {
            return s;
        }

        string output;
        int count = s.size() - 1;
        while (count >= 0)
        {
            while (count >= 0 && isspace(s[count]))
            {
                count--; 
            }

            int wordEnd = count;

            while (count >= 0 && !isspace(s[count]))
            {
                count--;
            }

            int wordStart = count + 1;

            output += s.substr(wordStart, wordEnd - wordStart + 1);

            if (count >= 0)
            {
                output += " ";
            }
        } 

        int check = output.size() - 1;
        while (check >= 0 && isspace(output[check]))
        {
            output = output.substr(0, check);
            check--;
        }

        return output;
    }
};