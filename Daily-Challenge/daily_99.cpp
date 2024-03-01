/* Daily Question: 2864. Maximum Odd Binary Number
 * by Tyler Edwards | February 28th, 2024 
 * Code Credit: sahilChoudhary16
 * You are given a binary string s that contains at least one '1'.
 * You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
 * Return a string representing the maximum odd binary number that can be created from the given combination.
 * Note that the resulting string can have leading zeros. */

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, cnt0 = 0;
        for (auto a : s) {
            if (a == '1') cnt1++;
            else if (a == '0') cnt0++;
        }
        string ans = string(cnt1 - 1, '1') + string(cnt0, '0') + '1';
        return ans;
    }
};