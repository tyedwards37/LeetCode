/* Daily Question: 3174. Clear Digits
 * by Tyler Edwards | February 9th, 2025 
 * Code Credit: Fahad Mubeen
 * You are given a string s.
 * Your task is to remove all digits by doing this operation repeatedly:
 * - Delete the first digit and the closest non-digit character to its left.
 * Return the resulting string after removing all digits. */

class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        int n = s.length();
        while (i < n) {
            // Check if the current character is a digit
            if (s[i] <= '9' && s[i] >= '0') {
                s[i] = '!'; // Mark the digit for deletion
                // Find the closest non-digit character to the left
                for (int j = i - 1; j >= 0; j--) {
                    if ((s[j] > '9' || s[j] < '0') && s[j] != '!') {
                        s[j] = '!'; // Mark the non-digit character for deletion
                        break;
                    }
                }
            }
            i++;
        }
        // Build the resulting string without the marked characters
        string res = "";
        for (int k = 0; k < n; k++) {
            if (s[k] != '!') res += s[k];
        }
        return res;
    }
};