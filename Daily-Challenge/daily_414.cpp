/* Daily Question: 2116. Check if a Parentheses String Can Be Valid
 * by Tyler Edwards | Janaury 11th, 2025 
 * Code Credit: Anujot Singh
 * A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
 * - It is ().
 * - It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
 * - It can be written as (A), where A is a valid parentheses string.
 * You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
 * - If locked[i] is '1', you cannot change s[i].
 * - But if locked[i] is '0', you can change s[i] to either '(' or ')'.
 * Return true if you can make s a valid parentheses string. Otherwise, return false. */

class Solution {
public:
    bool canBeValid(string s, string l) {
        if (s.size() % 2 == 1) return false;
        int total = 0, open = 0, closed = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if (l[i] == '0')
                total += 1;
            else if (s[i] == '(')
                open += 1;
            else if (s[i] == ')')
                closed += 1;
            if (total - open + closed < 0) return false;
        }
        total = open = closed = 0;
        for(int i = 0; i < s.size(); i++) {
            if (l[i] == '0')
                total += 1;
            else if (s[i] == '(')
                open += 1;
            else if (s[i] == ')')
                closed += 1;
            if (total + open - closed < 0) return false;
        }
        return true;
    }
};