/* Daily Question: 962. Maximum Width Ramp
 * by Tyler Edwards | October 9th, 2024 
 * Code Credit: lee215
 * A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
 * Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0. */

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || A[s.top()] > A[i])
                s.push(i);
        for (int i = n - 1; i > res; --i)
            while (!s.empty() && A[s.top()] <= A[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};