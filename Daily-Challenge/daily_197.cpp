/* Daily Question: 523. Continuous Subarray Sum
 * by Tyler Edwards | June 7th, 2024 
 * Code Credit: initishjha
 * Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
 * A good subarray is a subarray where:
 * - its length is at least two, and
 * - the sum of the elements of the subarray is a multiple of k. 
 * Note that: 
 * - A subarray is a contiguous part of the array. 
 * - An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k. */

#include <vector>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& numbers, int divisor) {
        ios::sync_with_stdio(false); 
        cin.tie(0); 
        cout.tie(0);

        int currentSum = numbers[0];
        int length = numbers.size();
        int index, tempSum;
        
        for (int i = 1; i < length; i++) {
            if (numbers[i] == numbers[i - 1] && numbers[i] == 0) {
                return true;
            }
            
            currentSum += numbers[i];
            
            if (currentSum % divisor == 0) {
                return true;
            }
            
            index = 0;
            tempSum = currentSum;
            
            while ((i - index) > 1 && tempSum >= divisor) {
                tempSum -= numbers[index++];
                
                if (tempSum % divisor == 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
};