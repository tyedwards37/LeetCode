/* Daily Question: 2762. Continuous Subarrays
 * by Tyler Edwards | December 13th, 2024  
 * Code Credit: Piyush Jaiswal
 * You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
 * - Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
 * Return the total number of continuous subarrays.
 * A subarray is a contiguous non-empty sequence of elements within an array. */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
            
            
            int l = 0, r = 0,j = 0;
            
            long long ans = 0;
            
            for(int i = 0;i<nums.size();i++){
                    
                    if(i == 0){ // First element
                            ans = ans + 1;
                            l = nums[i] - 2;  // range from a - 2
                            r = nums[i] + 2; // rane to a + 2
                    }else if(nums[i] >= l && nums[i] <= r){ // If new element belong to same range then 
                                    
                                    l = max(l,nums[i]-2); // take max from (a-2,b-2)
                                    r = min(r,nums[i]+2); // take min from (a+2,b+2)
                                    ans = ans + (i-j+1); // add subarray to answer
                                    
                    }else{ // If doest not belong to ranges try to remove from i-1 
                                  
                                   j = i-1;
                                   l = nums[i] - 2 , r = nums[i] + 2;  // new ranges
                                   while(nums[j]  >= nums[i] - 2 && nums[j] <= nums[i] + 2){
                                           
                                           l = max(l,nums[j] - 2); // take max 
                                           r = min(r,nums[j] + 2); // take min
                                           j--;
                                           
                                   }
                                   j++; 
                                    
                                  
                                   ans = ans + (i-j+1); 
                            
                    }
            }
            
            
            
            
            return ans;
        
    }
};