/* Daily Question: 2559. Count Vowel Strings in Ranges
 * by Tyler Edwards | Janaury 1st, 2025 (Happy New Years)
 * Code Credit: Kishan Kumar Patel
 * You are given a 0-indexed array of strings words and a 2D array of integers queries.
 * Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
 * Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
 * Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'. */

class Solution {
public:
    bool check(char c){ 
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||  c == 'u') return true; 
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v, ans;
        v.push_back(0);
        for(auto w: words){ 
            if( check(w[0]) && check(w.back()) ) v.push_back( v.back() + 1);  
            else v.push_back( v.back() );
        }
        for(auto q: queries) ans.push_back(v[q[1]+1] - v[q[0]]);
        return ans;
    }
};