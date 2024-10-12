/* Daily Question: 2406. Divide Intervals Into Minimum Number of Groups
 * by Tyler Edwards | October 11th, 2024 
 * Code Credit: lee215
 * You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
 * You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.
 * Return the minimum number of groups you need to make.
 * Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect. */

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> A;
        for (auto& v : intervals) {
            A.push_back({v[0], 1});
            A.push_back({v[1] + 1, -1});
        }
        int res = 0, cur = 0;
        sort(A.begin(), A.end());
        for (auto& v : A)
            res = max(res, cur += v[1]);
        return res;
    }
};