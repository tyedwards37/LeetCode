/* Daily Question: 349. Intersection of Two Arrays
 * by Tyler Edwards | March 9th, 2024 
 * Code Credit: StefanPochmann
 * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order. */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> out;
    for (int x : nums2)
        if (s.erase(x))
            out.push_back(x);
    return out;
    }
};