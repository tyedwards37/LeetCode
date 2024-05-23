/* Daily Question: 2597. The Number of Beautiful Subsets
 * by Tyler Edwards | May 22nd, 2024
 * Code Credit: shivamaggarwal513
 * You are given an array nums of positive integers and a positive integer k. 
 * A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k. 
 * Return the number of non-empty beautiful subsets of the array nums.
 * A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. 
 * Two subsets are different if and only if the chosen indices to delete are different. */

 class Solution {
private:
    int _beautifulSubsets(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) { // base case of the size of nums equaling 1 
            return 1;
        }
        int result = _beautifulSubsets(nums, k, freq, i + 1); // nums[i] not taken
        if (!freq[nums[i] - k] && !freq[nums[i] + k]) { // check if we can take nums[i]
            freq[nums[i]]++;  // increment the frequency at nums index i
            result += _beautifulSubsets(nums, k, freq, i + 1); // nums[i] taken
            freq[nums[i]]--; // decrement the frequency at nums index i
        }
        return result;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // intialize an unordered map 
        return _beautifulSubsets(nums, k, freq, 0) - 1; // -1 for empty subset
    }
};