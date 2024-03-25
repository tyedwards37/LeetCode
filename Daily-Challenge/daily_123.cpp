/* Daily Question: 287. Find the Duplicate Number
 * by Tyler Edwards | March 23rd, 2024 
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and uses only constant extra space. */
 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer; // creating an empty array for the answer

        if (nums.size() > 1) // checking to make sure the array has more than one value 
        {
            unordered_map<int, int> map; // creating a map to store the frequency of values
            for(auto n : nums) { // loops through the values in the array
                map[n]++; // if value is found increment by 1 
                if (map[n] > 1) { // check if value is greater than 1 
                    answer.push_back(n); // pushing the number to the array
                }
            }
        }

        return answer; // return the array 
    }
};