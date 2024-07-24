/* Daily Question: 2191. Sort the Jumbled Numbers
 * by Tyler Edwards | July 23rd, 2024 
 * Code Credit: anwendeng
 * You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.
 * The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.
 * You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.
 * Notes:
 * - Elements with the same mapped values should appear in the same relative order as in the input.
 * - The elements of nums should only be sorted based on their mapped values and not be replaced by them. */

class Solution {
public:
    static int convert(int x, vector<int>& mapping){
        if (x==0) return mapping[0];//  edge case
        int z=0;
        for(int pow10=1; x>0; pow10*=10){
            auto [q, r]=div(x, 10);
            z+=mapping[r]*pow10;
            x=q;
        }
        return z;
    }

    static vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n=nums.size();
        vector<long long> mapNum(n);
        for(int i=0; i<n; i++){
            int x=nums[i];
            mapNum[i]=((long long)convert(x, mapping)<<32)+i;//(mapping nums, idx)
        }
        sort(mapNum.begin(), mapNum.end());// Use default sort is better
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            ans[i]=nums[mapNum[i]& 0xffffffff];//unpack
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();