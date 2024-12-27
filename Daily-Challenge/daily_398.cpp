/* Daily Question: 1014. Best Sightseeing Pair
 * by Tyler Edwards | December 26th, 2024 
 * Code Credit: lee
 * You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
 * The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
 * Return the maximum score of a pair of sightseeing spots. */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0, cur = 0;
        for (int a: A) {
            res = max(res, cur + a);
            cur = max(cur, a) - 1;
        }
        return res;
    }
};