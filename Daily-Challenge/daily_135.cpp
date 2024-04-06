/* Daily Question: 1249. Minimum Remove to Make Valid Parentheses
 * by Tyler Edwards | April 5th, 2024 
 * Code Credit: votrubac
 * Given a string s of '(' , ')' and lowercase English characters.
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
 * Formally, a parentheses string is valid if and only if:
 * - It is the empty string, contains only lowercase characters, or
 * - It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * - It can be written as (A), where A is a valid string. */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // creates a stack of integers
        for (auto i = 0; i < s.size(); ++i) { // loop for all the values in the given string
            if (s[i] == '(') st.push(i); // pushes the index to the stack if the character is a '('
            if (s[i] == ')') { // if the character is a ')' it takes this path
                if (!st.empty()) st.pop(); // if the stack is not empty, pop a value off the stack
                else s[i] = '*'; // if it isn't empty, replace that index of the string with a '*'
            }
        }
        while (!st.empty()) { // loop while the stack isn't empty
            s[st.top()] = '*'; // for the top value in the stack, reaplce that index of the string with a '*'
            st.pop(); // pop a value off the stack 
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end()); // remove all of the '*' from the string, essentially cleaning it up
        return s; // return the newly modified string
    }
};