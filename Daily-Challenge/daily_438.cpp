/* Daily Question: 1790. Check if One String Swap Can Make Strings Equal
 * by Tyler Edwards | February 4th, 2025 
 * Code Credit: seek
 * You are given two strings s1 and s2 of equal length. 
 * A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
 * Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false. */

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // find the number of diff positions
        vector<int> diff_pos;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                diff_pos.emplace_back(i);
            // If there are more than 2 char positions that differ, 
            // the single swap op cannot anyway make the two strings equal
            if(diff_pos.size() > 2)
                return false;
        }
        // when the chars are exactly the same
        if(diff_pos.empty())
            return true;
        // only one pair of diff positions, check if swapping makes them equal
        if(diff_pos.size() == 2) 
            swap(s1[diff_pos[0]], s1[diff_pos[1]]);
        
        return s1 == s2;
    }
};