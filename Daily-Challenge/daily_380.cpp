/* Daily Question: 3152. Special Array II
 * by Tyler Edwards | December 8th, 2024  
 * Code Credit: innocentCoder
 * An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
 * You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.
 * Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special. */

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> converted(1, 0);
        for(int i = 1, j = 0; i < nums.size(); ++i){
            if( (nums[i]%2) == (nums[i-1]%2) ) j++;
            converted.push_back(j);
        }
        for(auto q: queries) ans.push_back( converted[q[0]] == converted[q[1]] );
        return ans;
    }
};