/* Daily Question: 1716. Calculate Money in Leetcode Bank
 * by Tyler Edwards | December 6th, 2023 
 * Code Credit: TovAm
 * You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
 * A substring is a contiguous sequence of characters within a string. */

class Solution {
public:
    string largestOddNumber(string num) 
    {
        for (int i = num.size() - 1; i >= 0; --i)
        {
          if(int(num[i] % 2))
          {
            return num.substr(0, i + 1);
          }
        }

        return "";
    }
};