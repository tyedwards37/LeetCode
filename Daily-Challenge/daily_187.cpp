/* Daily Question: 1208. Get Equal Substrings Within Budget
 * by Tyler Edwards | May 27th, 2024 (100th day!)
 * Code Credit: MrAke
 * You are given two strings s and t of the same length and an integer maxCost.
 * You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
 * Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. 
 * If there is no substring from s that can be changed to its corresponding substring from t, return 0. */

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(); // intialize an integer to the size of the string
        int start = 0; // intialize a starting variable to 0
        int current_cost = 0; // intialize a current cost integer to 0
        int max_length = 0; // intialize a max length integer to 0

        for (int end = 0; end < n; ++end) { // loop for the length of the string and intialize an end integer
            current_cost += abs(s[end] - t[end]); // add to the current cost the absolute value of the character at index end of the string s minus the value of the character at the index end of string t

            while (current_cost > maxCost) { // loop while current cost is greater than the given max cost
                current_cost -= abs(s[start] - t[start]); // subtract from the current cost the absolute value of the character at index start of the string s minus the value of the character at the index start of string t
                ++start; // increment the start variable
            }

            max_length = max(max_length, end - start + 1); // set max length to the max of the current max length and the end index minus start plus 1
        }

        return max_length; // return the max length
    }
};