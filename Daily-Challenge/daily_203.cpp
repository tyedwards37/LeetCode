/* Daily Question: 945. Minimum Increment to Make Array Unique
 * by Tyler Edwards | June 13th, 2024 
 * You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
 * Return the minimum number of moves to make every value in nums unique.
 * The test cases are generated so that the answer fits in a 32-bit integer. */

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort the nums array in increasing order

        int count = 0; // intialize an integer to the hold the number of changes made
        for (int i = 1; i < nums.size(); i++) { // loop for the size of the array 
            while (nums[i] <= nums[i - 1]) { // loops until the value of nums at index i is greater than the value that precedes it
                nums[i] = nums[i] + 1; // increment the value within the nums array
                count++; // increment the count variable
            }
        }

        return count; // return the final value of the count variable
    }
};

// Solution Evaluation: Poor Runtime due to the embedded while loop inside the for loop