/* Daily Question: 201. Bitwise AND of Numbers Range
 * by Tyler Edwards | February 20th, 2024 
 * Code Credit: applewolf
 * Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};