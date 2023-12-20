/* LeetCode Day 50: 215. Kth Largest Element in an Array (Medium) 54/75 
 * Tyler Edwards | December 19th, 2023
 * Code Credit: jianchao-li
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Can you solve it without sorting? */

 class Solution 
 {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int left = 0, right = nums.size() - 1, kth;
        while (true) 
        {
            int idx = partition(nums, left, right);
            if (idx == k - 1) 
            {
                kth = nums[idx];
                break;
            }

            if (idx < k - 1) 
            {
                left = idx + 1;
            } 

            else 
            {
                right = idx - 1;
            }
        }
        return kth;
    }
private:
    int partition(vector<int>& nums, int left, int right) 
    {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) 
        {
            if (nums[l] < pivot && nums[r] > pivot) 
            {
                swap(nums[l++], nums[r--]);
            }

            if (nums[l] >= pivot) 
            {
                l++;
            }

            if (nums[r] <= pivot) 
            {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};