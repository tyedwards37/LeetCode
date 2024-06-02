/* Daily Question: 344. Reverse String
 * by Tyler Edwards | June 1st, 2024
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory. */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1; // intialize an integer that will act as the a pointer to the left and right side of the string respectively
        char temp; // intialize a temp chacracter to hold one of the values whileit is being replaced

        while (left < right) { // loop while the left pointer is less than the right pointer (there is still letters to swap)
            temp = s[left]; // sets the temp character to the character at index left of the given string
            s[left] = s[right]; // sets the charcter at index left to the chracter at index right
            s[right] = temp; // sets the character at index right to the stored value
            left++; // increment the left pointer (move to next letter)
            right--; // decrement the right pointer (moving from last character towards middle)
        }
    }
};