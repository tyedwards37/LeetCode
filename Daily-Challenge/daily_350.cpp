/* Daily Question: 1829. Maximum XOR for Each Query
 * by Tyler Edwards | November 7th, 2024  
 * Code Credit: Vlad
 * You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:
 * 1. Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
 * 2. Remove the last element from the current array nums.
 * Return an array answer, where answer[i] is the answer to the ith query. */

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& n, int maximumBit) {
        vector<int> res(n.size());
        int val = (1 << maximumBit) - 1;
        for (int i = 0; i < n.size(); ++i)
            res[n.size() - i - 1] = val ^= n[i];
        return res;
    }
};