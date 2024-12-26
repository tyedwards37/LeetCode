/* Daily Question: 494. Target Sum
 * by Tyler Edwards | December 25th, 2024 (Merry Christmas)
 * Code Credit: Shubham Prasad
 * You are given an integer array nums and an integer target.
 * You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
 * - For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
 * Return the number of different expressions that you can build, which evaluates to target. */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x: nums)
            sum += x;
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int s1 = (sum + target)/2;
        int ans = subsetCount(nums,s1);
        return ans;
    }
    
    int subsetCount(vector<int>& nums, int s1){
        int n = nums.size();
        int t[n+1][s1+1];
        t[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            t[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        
        return t[n][s1];
    }
};