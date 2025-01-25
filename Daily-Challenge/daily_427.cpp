/* Daily Question: 2948. Make Lexicographically Smallest Array by Swapping Elements
 * by Tyler Edwards | Janaury 24th, 2025 
 * Code Credit: I AM WHO
 * You are given a 0-indexed array of positive integers nums and a positive integer limit.
 * In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
 * Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
 * An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. 
 * For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10. */

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> b;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
            b.push_back(make_pair(nums[i], i));

        sort(b.begin(), b.end(), [](const auto& x, const auto& y) {
            return x.first < y.first;
        });
        vector<vector<pair<int, int>>> c = {{b[0]}};

        for (int i = 1; i < n; ++i) {
            if (b[i].first - b[i - 1].first <= limit)
                c.back().push_back(b[i]);
            else
                c.push_back({b[i]});
        }

        for (const auto& t : c) {
            vector<int> ind;
            for (const auto& p : t)
                ind.push_back(p.second);
            sort(ind.begin(), ind.end());

            for (int i = 0; i < ind.size(); ++i)
                nums[ind[i]] = t[i].first;
        }
        return nums;
    }
};