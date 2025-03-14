/* Daily Question: 2779. Maximum Beauty of an Array After Applying Operation
 * by Tyler Edwards | December 10th, 2024  
 * Code Credit: Codensity_30
 * You are given a 0-indexed array nums and a non-negative integer k.
 * In one operation, you can do the following:
 * - Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
 * - Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
 * The beauty of the array is the length of the longest subsequence consisting of equal elements.
 * Return the maximum possible beauty of the array nums after applying the operation any number of times.
 * Note that you can apply the operation to each index only once.
 * A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements. */

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            // here nums[i] = maxi and nums[start] = mini
            // while window is not vaild increase the current minimum 
            while(nums[i]-nums[start] > 2*k)
                start++;
            // the current window i.e. [start ... i] is valid so consider it
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};