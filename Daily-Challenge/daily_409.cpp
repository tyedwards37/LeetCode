/* Daily Question: 1408. String Matching in an Array
 * by Tyler Edwards | Janaury 6th, 2025 
 * Code Credit: fa5trac3r
 * Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
 * A substring is a contiguous sequence of characters within a string */

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(auto i:words)
        {
            for(auto j: words)
            {
                if(i==j) continue;
                if(j.find(i)!=-1)
                {
                    ans.push_back(i);
                    break;                    
                }
            }
        }
        return ans;
    }
};