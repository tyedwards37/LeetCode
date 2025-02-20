/* Daily Question: 1980. Find Unique Binary String
 * by Tyler Edwards | February 19th, 2025 
 * Code Credit: ashucrma
 * Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. 
 * If there are multiple answers, you may return any of them. */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0; i<nums.size(); i++) 
            ans+= nums[i][i]=='0' ? '1' : '0';          // Using ternary operator
			// ans+=to_string(1-(nums[i][i]-'0'));     // Alternate:  or use to_string & 1-x to flip
        return ans;
    }
};