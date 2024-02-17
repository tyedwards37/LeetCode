/* Daily Question: 1642. Furthest Building You Can Reach
 * by Tyler Edwards | February 16th, 2024 
 * Code Credit: lee215
 * You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
 * You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
 * While moving from building i to building i+1 (0-indexed),
 * - If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
 * - If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
 * Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally. */

 class Solution {
    public:
            int furthestBuilding(vector<int>& A, int bricks, int ladders) {
            priority_queue<int> pq;
            for (int i = 0; i < A.size() - 1; i++) {
                int d = A[i + 1] - A[i];
                if (d > 0)
                    pq.push(-d);
                if (pq.size() > ladders) {
                    bricks += pq.top();
                    pq.pop();
                }
                if (bricks < 0)
                    return i;
            }
            return A.size() - 1;
        }
    };