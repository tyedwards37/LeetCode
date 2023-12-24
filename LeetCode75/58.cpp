/* LeetCode Day 54: 2300. Successful Pairs of Spells and Potions (Medium) 58/75 
 * Tyler Edwards | December 23rd, 2023
 * Code Credit: rahulvarma5297
 * You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
 * You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:
 * - You will run k sessions and hire exactly one worker in each session.
 * - In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
 *   - For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
 *   - In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
 * - If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
 * - A worker can only be chosen once. 
 * Return the total cost to hire exactly k workers. */

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        int i = 0;
        int j = costs.size() - 1;

        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        long long answer = 0;
        while (k--)
        {
            while (pq1.size() < candidates && i <= j)
            {
                pq1.push(costs[i++]);
            }

            while (pq2.size() < candidates && i <= j)
            {
                pq2.push(costs[j--]);
            }

            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (t1 <= t2)
            {
                answer += t1;
                pq1.pop();
            }

            else
            {
                answer += t2;
                pq2.pop();
            }
        }

        return answer;
    }
};