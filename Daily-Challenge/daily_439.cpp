/* Daily Question: 1726. Tuple with Same Product
 * by Tyler Edwards | February 5th, 2025 
 * Code Credit: GoogleNick
 * Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d. */


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                int prod = nums[i] * nums[j];
				/*Every tuple has 8 permutations*/
                res += 8 * umap[prod];
                ++umap[prod];
            }
        }
        return res;
    }
};