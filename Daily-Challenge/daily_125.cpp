/* Daily Question: 713. Subarray Product Less Than K
 * by Tyler Edwards | March 26th, 2024 
 * Code Credit: alexander
 * Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k. */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0; // no combinations of positive integers can be less than 0
        int count = 0; // intialize a count variable to 0 
        int product = 1; // intialize a product variable to 1 (not 0 bc that would make everything 0)
        for (int i = 0, j = 0; j < nums.size(); j++) { // loops for the size of array 
            product *= nums[j]; // multiply the existing product variable by the value of the array
            while (i <= j && product >= k) { // if i is less than j and product is less than AND greater than or equal to our max value k, then loop
                product /= nums[i++]; // reudce the numbers on the left of the window by incrementing i 
            }
            count += j - i + 1; // size of the current window
        }
        return count; // return the final count
    }
};