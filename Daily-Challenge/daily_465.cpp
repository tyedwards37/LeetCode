/* Daily Question: 2529. Maximum Count of Positive Integer and Negative Integer
 * by Tyler Edwards | March 11th, 2025 
 * Code Credit: Otabek Kholmirzaev
 * Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
 * - In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
 * Note that 0 is neither positive nor negative. */

 class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int neg_count = binarySearch(nums, 0);
            int pos_count = nums.size() - binarySearch(nums, 1);
            return max(neg_count, pos_count);
        }
    
    private:
        int binarySearch(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1, result = nums.size();
            
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    result = mid;
                    right = mid - 1;
                }
            }
            
            return result;
        }
    };

