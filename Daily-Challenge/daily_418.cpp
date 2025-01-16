/* Daily Question: 2425. Bitwise XOR of All Pairings
 * by Tyler Edwards | Janaury 14th, 2025 
 * Code Credit: lee
 * You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. 
 * There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).
 * Return the bitwise XOR of all integers in nums3. */

class Solution {
public:
    int xorAllNums(vector<int>& A, vector<int>& B) {
        int x = 0, y = 0;
        for (int a : A)
            x ^= a;
        for (int b : B)
            y ^= b;
        return (A.size() % 2 * y) ^ (B.size() % 2 * x);
    }
};