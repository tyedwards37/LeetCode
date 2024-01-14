/* LeetCode Beginner's Guide: 1342. Number of Steps to Reduce a Number to Zero (4/6)
 * by Tyler Edwards | January 14th, 2024 
 * Given an integer num, return the number of steps to reduce it to zero.
 * In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it. */

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }

        int count = 0;

        if (num % 2 == 0) {
            num /= 2;
            count++;
        }

        if (num % 2 == 1) {
            num -= 1;
            count++;
        }
        
        return numberOfSteps(num) + count;
    }
};