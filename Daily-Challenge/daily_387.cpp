/* Daily Question: 3264. Final Array State After K Multiplication Operations I
 * by Tyler Edwards | December 15th, 2024  
 * Code Credit: Kishan Kumar Patel
 * You are given an integer array nums, an integer k, and an integer multiplier.
 * You need to perform k operations on nums. In each operation:
 * - Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
 * - Replace the selected minimum value x with x * multiplier.
 * Return an integer array denoting the final state of nums after performing all k operations. */

 class Solution {
    public:
        vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
            priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
            for(auto i = 0; i < nums.size(); ++i) pq.push({nums[i], i});
            for(int i = 0; i < k; ++i){
                auto [num, ind] = pq.top(); pq.pop();
                nums[ind] = num * multiplier;
                pq.push({nums[ind], ind});
            }
            return nums;
        }
    };