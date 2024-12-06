/* Daily Question: 2554. Maximum Number of Integers to Choose From a Range I
 * by Tyler Edwards | December 5th, 2024  
 * Code Credit: Siddharth Gangwar
 * You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
 * - The chosen integers have to be in the range [1, n].
 * - Each integer can be chosen at most once.
 * - The chosen integers should not be in the array banned.
 * - The sum of the chosen integers should not exceed maxSum.
 * Return the maximum number of integers you can choose following the mentioned rules. */

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        unordered_set<int> s(begin(banned), end(banned));
        for(int i = 1; i <= n; ++i){
            if(s.find(i) == s.end() && maxSum - i >= 0) { ans++; maxSum -= i; }
        }
        return ans;
    }
};