/* Daily Question: 1310. XOR Queries of a Subarray
 * by Tyler Edwards | September 10th, 2024 
 * Code Credit: Ajna
 * You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
 * For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ). 
 * Return an array answer where answer[i] is the answer to the ith query. */

class Solution {
public:
    vector<int> xorQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 1; i < A.size(); ++i)
            A[i] ^= A[i - 1];
        for (auto &q: queries)
            res.push_back(q[0] > 0 ? A[q[0] - 1] ^ A[q[1]] : A[q[1]]);
        return res;
    }
};