/* LeetCode Day 32: Removing Stars From a String (2390) (Medium) 34/75 
 * by Tyler Edwards | November 25th, 2023 
 * You are given a string s, which contains stars *. In one operation, you can:
 * - Choose a star in s. 
 * - Remove the closest non-star character to its left, as well as remove the star itself.
 * Return the string after all stars have been removed. */

class Solution {
public:
    string removeStars(string s) 
    {
        string answer = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                answer.pop_back();
            }

            else
            {
                answer += s[i];
            }
        }

        return answer;
    }
};
