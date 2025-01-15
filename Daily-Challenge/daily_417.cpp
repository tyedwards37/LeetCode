/* Daily Question: 2429. Minimize XOR
 * by Tyler Edwards | Janaury 13th, 2025 
 * Code Credit: Amritesh Chandra
 * Given two positive integers num1 and num2, find the positive integer x such that:
 * - x has the same number of set bits as num2, and
 * - The value x XOR num1 is minimal.
 * Note that XOR is the bitwise XOR operation.
 * Return the integer x. The test cases are generated such that x is uniquely determined.
 * The number of set bits of an integer is the number of 1's in its binary representation. */

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a = __builtin_popcount(num1), b = __builtin_popcount(num2), res = num1;
        for (int i = 0; i < 32; ++i) {
            if (a > b && ((1 << i) & num1) > 0) {
                res ^= 1 << i;
                a--;
            }
            if (a < b && ((1 << i) & num1) == 0) {
                res ^= 1 << i;
                a++;
            }
        }
        return res;
    }
};