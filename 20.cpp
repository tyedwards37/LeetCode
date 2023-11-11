/* LeetCode Day 18: N-th Tribonacci Number (Easy) 20/75 
 * by Tyler Edwards | November 11th, 2023 
 * Desc: You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1. Return the minimum cost to reach the top of the floor. */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int size = cost.size();

        for (int i = 2; i < size; i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        return min(cost[size - 1], cost[size - 2]);
    }
};