/* Daily Question: 921. Minimum Add to Make Parentheses Valid
 * by Tyler Edwards | October 8th, 2024 
 * Code Credit: lee215
 * A parentheses string is valid if and only if:
 * - It is the empty string,
 * - It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * - It can be written as (A), where A is a valid string.
 * You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
 * - For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
 * Return the minimum number of moves required to make s valid. */

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, right = 0;
        for (char c : S)
            if (c == '(')
                right++;
            else if (right > 0)
                right--;
            else
                left++;
        return left + right;
    }
};