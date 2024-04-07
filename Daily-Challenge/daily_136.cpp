/* Daily Question: 678. Valid Parenthesis String
 * by Tyler Edwards | April 6th, 2024 
 * Code Credit: lee215
 * Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
 * The following rules define a valid string:
 * - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * - Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "". */

class Solution {
public:
        bool checkValidString(string s) {
        int cmin = 0, cmax = 0; // creates one variable that maxs the max number of open parnethesis and another that counts the minimum
        for (char c : s) { // loops for every character in the given string
            if (c == '(') // checks for a left parenthesis
                cmax++, cmin++; // incremets both the max and the min
            if (c == ')') // checks for a right parenthesis 
                cmax--, cmin = max(cmin - 1, 0); // decrements the max and sets the min to either the min - 1 or 0, depending on which is greater 
            if (c == '*') // checks for a '*' character
                cmax++, cmin = max(cmin - 1, 0); // increments the max and sets the min to either the min - 1 or 0, depending on which is greater 
            if (cmax < 0) return false; // if the max is less than 0 by the end of the loop return false
        }
        return cmin == 0; // if the min is equal to 0 then return true
    }
};