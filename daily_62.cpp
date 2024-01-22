/* Daily Question: 645. Set Mismatch
 * by Tyler Edwards | January 21st, 2024 
 * Code Credit: MarkSPhilip31
 * You have a set of integers s, which originally contains all the numbers from 1 to n. 
 * Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 * You are given an integer array nums representing the data status of this set after the error.
 * Find the number that occurs twice and the number that is missing and return them in the form of an array. */


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for (int i = 1;i <= n; i++) mp[i]++;

        for (auto a :nums) mp[a]--;
        int duplicate  = 0, missing = 0;

        for(auto a : mp){
            if (a.second == -1) duplicate = a.first;
            if (a.second == 1) missing = a.first;
        }

        return {duplicate, missing};
    }
};


