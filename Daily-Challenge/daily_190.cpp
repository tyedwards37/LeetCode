/* Daily Question: 260. Single Number III
 * by Tyler Edwards | May 30th, 2024
 * Code Credit: himanshukumar4642
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
 * You can return the answer in any order. 
 * You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.*/

 class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
	int x = 0; // intialize an integer to 0
	for (const int curr: nums) { // loop for every values in the nums array
		x ^= curr;    // xor all numbers, so the duplicates are cancelled
	}

	int bit; // intialize an integer to hold the bit 
	for (int i=0; i<32; ++i) { // loop for 32 times
		if (x & (1<<i)) { // checks with a bitwise shift left for the value of 1 to the bit integer then the bitwise AND with x 
			bit = i; // sets the bit int to the i 
			break; // break the loop 
		}
	}

	int first = 0; // intialize an integer for the first number
	for (int a: nums) { // loop for each of the values in the nums array 
		if (a & (1<<bit)) { // checks with a bitwise shift left for the value of 1 to the bit integer then the bitwise AND with a 
			first ^= a; // perform the XOR operator with the first and a values
		}
	}

	int second = first^x; // set the second integer to the first XOR'd with the x integer
	return {first, second}; // return an array with the first and second values
    }
};