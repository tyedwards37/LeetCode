/* LeetCode Day 52: 2542. Maximum Subsequence Score (Medium) 56/75 
 * Tyler Edwards | December 21st, 2023
 * Code Credit: lee215
 * You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
 * For chosen indices i0, i1, ..., ik - 1, your score is defined as:
 * - The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
 * - It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
 * Return the maximum possible score.
 * A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements. */

class Solution {
public:
    long long maxScore(vector<int>& speed, vector<int>& efficiency, int k) 
    {
        int n = speed.size();
        vector<pair<int, int>> ess(n);

        for (int i = 0; i < n; i++)
        {
            ess[i] = {efficiency[i], speed[i]};
        }

        sort(rbegin(ess), rend(ess));
        long long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq;

        for (auto& [e, s] : ess)
        {
            pq.emplace(s);
            sumS += s;

            if (pq.size() > k)
            {
                sumS -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
            {
                res = max(res, sumS * e);
            }
        }

        return res;
    }
};