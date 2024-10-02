/* Daily Question: 1331. Rank Transform of an Array
 * by Tyler Edwards | October 1st, 2024 
 * Code Credit: lee215
 * Given an array of integers arr, replace each element with its rank.
 * The rank represents how large the element is. The rank has the following rules:
 * - Rank is an integer starting from 1.
 * - The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
 * - Rank should be as small as possible. */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> A(arr);
        sort(A.begin(), A.end());
        unordered_map<int, int> rank;
        for (int& a : A)
            rank.emplace(a, rank.size() + 1);
        for (int i = 0; i < A.size(); ++i)
            A[i] = rank[arr[i]];
        return A;
    }
};