/* Daily Question: 650. 2 Keys Keyboard
 * by Tyler Edwards | August 18th, 2024 
 * Code Credit: MrAke
 * There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
 * - Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
 * - Paste: You can paste the characters which are copied last time.
 * Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen. */

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        int steps = 0;
        int factor = 2;
        
        while (n > 1) {
            while (n % factor == 0) {
                steps += factor;
                n /= factor;
            }
            factor++;
        }
        
        return steps;
    }
};