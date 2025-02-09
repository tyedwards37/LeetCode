/* Daily Question: 2364. Count Number of Bad Pairs
 * by Tyler Edwards | February 8th, 2025 
 * Code Credit: Curios
 * You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
 * Return the total number of bad pairs in nums. */

class Solution {
public:
    long long countBadPairs(vector<int>& a,long cnt=0) {
        unordered_map<int,int> mp;
        for(int i=0;i<size(a);i++)
            cnt+= i- mp[i-a[i]]++;
        return cnt;
    }
};  
