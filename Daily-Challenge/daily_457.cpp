/* Daily Question: 2460. Apply Operations to an Array
 * by Tyler Edwards | February 28th, 2025 
 * Code Credit: Yanru Cheng
 * You are given a 0-indexed array nums of size n consisting of non-negative integers.
 * You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:
 * - If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
 * After performing all the operations, shift all the 0's to the end of the array.
 * - For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
 * Return the resulting array.
 * Note that the operations are applied sequentially, not all at once. */

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i+1 < nums.size(); ++i){
            if(nums[i] == nums[i+1]){          //update values of ith and (i+1)th value
                nums[i] = 2*nums[i]; 
                nums[i+1] = 0;
            }
        }
        int i = 0;
        for(auto n: nums){                     // collect all noon zero values at front
            if(n != 0) nums[i++] = n;
        }
        while(i < nums.size()) nums[i++] = 0;  //set values to zero for remainintg ith element
        return nums;
    }
};