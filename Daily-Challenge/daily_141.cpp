/* Daily Question: 42. Trapping Rain Water
 * by Tyler Edwards | April 11th, 2024 
 * Code Credit: mcrystal
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // intialize an integerto the number of values in the array
        int left = 0, right = n - 1; // intialize an integer to become a left pointer that starts at 0 and another to become a right pointer that starts at the final index (amount of values - 1)
        int answer = 0; // intialize an integer to hold the final amount of rain water
        int maxLeft = 0, maxRight = 0; // intialize two integers to store the max left value and the max right value to see how much water can be stored by that crater
        while(left <= right) { // loop while the left pointer is less or equal to the right pointer 
            if(height[left] <= height[right]) { // checks if the value at index "left" is less than then value at index "right"
                if(height[left] >= maxLeft) maxLeft = height[left]; // checks if the value in the array at index "left" is greater than or equal to maxLeft and sets maxLeft to that value if it is 
                else answer += maxLeft - height[left]; // if the value at "left" index isn't greater add maxLeft - the value at index "left"
                left++; // increment the left integer
            }

            else { // if the value at index "right" is less than the value at at index "left"
                if(height[right] >= maxRight) maxRight= height[right]; // checks if the value in the array at index "right" is greater than or equal to maxRight and sets maxRight to that value if it is 
                else answer += maxRight - height[right]; // if the value at "right" index isn't greater add maxRight - the value at index "right"
                right--; // decrement the "right" integer
            }
        }

        return answer; // return the final amount of rain that the array holds 
    }
};