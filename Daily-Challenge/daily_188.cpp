/* Daily Question: 1404. Number of Steps to Reduce a Number in Binary Representation to One
 * by Tyler Edwards | May 28th, 2024
 * Code Credit: shubham6762
 * Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
 * - If the current number is even, you have to divide it by 2.
 * - If the current number is odd, you have to add 1 to it.
 * It is guaranteed that you can always reach one for all test cases. */

class Solution {
public:
    int numSteps(string s) {
        int n = s.length(); // intializes an integer for the length of the given string
        int ans = n - 1, carry = 0; // intializes two integers for the answer with an intial value of length - 1 and a carry set to 0 

        for (int i = n - 1; i > 0; i--) { // loop for the size of the string minus 1
            if (s[i] - '0' + carry == 1) { // check fi the character at index i of the string plus the carry is equal to 1
                ans++; // increment the answer by 1 
                carry = 1; // set the carry value to 1 
            }
        }

        return ans + carry; // return the answer plus the carry
    }
};