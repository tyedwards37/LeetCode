/* Daily Question: 633. Sum of Square Numbers
 * by Tyler Edwards | June 16th, 2024 
 * Code Credit: laggerk
 * Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c. */

#include <cmath>  // For sqrt

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;  // Left pointer starts at 0
        long right = static_cast<long>(sqrt(c));  // Right pointer starts at the integer square root of c
        
        while (left <= right) {
            long curr_sum = left * left + right * right;  // Calculate sum of squares of the two pointers
            if (curr_sum == c) return true;  // If sum equals c, return true
            if (curr_sum < c) {
                left++;  // If sum is less than c, move left pointer right
            } else {
                right--;  // If sum is greater than c, move right pointer left
            }
        }
        
        return false;  // If no such pair is found, return false
    }
};