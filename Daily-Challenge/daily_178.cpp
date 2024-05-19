/* Daily Question: 3068. Find the Maximum Sum of Node Values
 * by Tyler Edwards | May 18th, 2024 (7 hours in the car)
 * Code Credit: lee_215
 * There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. 
 * You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.
 * Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:
 * - Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
 *    - nums[u] = nums[u] XOR k
 *    - nums[v] = nums[v] XOR k */

class Solution {
public:
        long long maximumValueSum(vector<int>& A, int k, vector<vector<int>>& edges) {
            long long res = 0; // intialize a long long to a designated answer variable
            int d = 1 << 30, c = 0; // int d is set to 2^30 and int c is set to 0
            for (int a : A) { // loop for teh array of integers 
                int b = a ^ k; // b is set to the bitwise XOR operator between a and k
                res += max(a, b); // the max between the a and b variables is added to the current result value
                c ^= a < b; // if a is less than b it flips the values to their respective binary number
                d = min(d, abs(a - b)); // sets d to the minimum value between the current da and the absolute value of a - b
            }
            return res - d * c; // returns the result value - (d times c)
    }
};