/* Daily Question: 2485. Find the Pivot Integer
 * by Tyler Edwards | March 12th, 2024 
 * Code Credit: votrubac
 * Given a positive integer n, find the pivot integer x such that:
 * - The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
 * Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input. */

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2, x = sqrt(sum);
        return x * x == sum ? x : -1;
    }
};