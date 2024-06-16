/* Daily Question: 330. Patching Array
 * by Tyler Edwards | June 15th, 2024 
 * Code Credit: bhanu_bhakta
 * Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
 * Return the minimum number of patches required. */

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // intialize a miss value to 1
        int result = 0; // intialize the result to a starting value of 0
        size_t i = 0; // intialize an index i starting at 0

        while (miss <= n) { // loop while the miss value is less than or equal to the given value n
            if (i < nums.size() && nums[i] <= miss) { // check if the index i is less than the size of the given nums array and that the value is less than or equal to miss at that index
                miss += nums[i]; // add the value to miss total
                i++; // increment the i index
            } else {
                miss += miss; // double the miss value
                result++; // increment the result value
            }
        }

        return result; // return the final result value
    }
};