/* Daily Question: 1593. Split a String Into the Max Number of Unique Substrings
 * by Tyler Edwards | October 20th, 2024 
 * Code Credit: binayKr
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.
 * You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. 
 * However, you must split the substrings such that all of them are unique.
 * A substring is a contiguous sequence of characters within a string. */

class Solution {
public:
    unordered_set<string> st;
    int maxUniqueSplit(string &s, int p = 0) {
        if (p == s.size())
            return 0;
        int res = -1;
        for (int sz = 1; p + sz <= s.size(); ++sz) {
            auto it = st.insert(s.substr(p, sz));
            if (it.second) {
                int n_res = maxUniqueSplit(s, p + sz);
                if (n_res != -1)
                    res = max(res, 1 + n_res);
                st.erase(it.first);
            }    
        }
        return res;
    }
};