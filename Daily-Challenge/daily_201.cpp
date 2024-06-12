/* Daily Question: 75. Sort Colors
 * by Tyler Edwards | June 11th, 2024 
 * Code Credit: amanrathore48
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function. */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1; // intialize two ints to 0 and one to the size of the nums array that will acta as pointers 

        while (mid <= high) { // loops while the mid pointer is less than the high pointer
            if (nums[mid] == 0) { // checks if the value at mid is 0 (red)
                swap(nums[low], nums[mid]); // swaps the values of the array at the index of low and mid, sending the zero towards the beginning of the list

                low++; // increments the low integer
                mid++; // increments the mid integer
            }

            else if (nums[mid] == 1) { // checks if the value at mid is 1 (white)
                mid++; // increments just the mid pointer this time
            }

            else { // since its not 0 or 1 the value must be 2
                swap(nums[mid], nums[high]); // swaps the values of the array at the index of mid and high, sending the two towards the end of the list
                high--;
            }
        }
    }
};