/* Daily Question: 2563. Count the Number of Fair Pairs
 * by Tyler Edwards | November 12th, 2024  
 * Code Credit: Akbar
 * Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
 * A pair (i, j) is fair if:
 * - 0 <= i < j < n, and
 * - lower <= nums[i] + nums[j] <= upper */

class Solution {
public:
    long long countFairPairs(vector<int>& v, int first_val, int last_val) {
        deque<int>vc;
        sort(v.begin(),v.end());
        for(auto i:v) vc.push_back(i);
        long long int ans=0;
        for(int i=0;i<v.size();i++)
        {
            vc.pop_front();
            int lower=first_val-v[i],upper=last_val-v[i];
            auto left=lower_bound(vc.begin(),vc.end(),lower);
            auto right=upper_bound(vc.begin(),vc.end(),upper);
            ans+=(right-left);
        }
        return ans;
    }
};