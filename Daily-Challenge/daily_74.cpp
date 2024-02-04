/* Daily Question: 76. Minimum Window Substring
 * by Tyler Edwards | February 3rd, 2024 
 * Code Credit: zjh08177
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
 * If there is no such substring, return the empty string "".
 * The testcases will be generated such that the answer is unique. */

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; 
            while(counter==0){ 
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++; 
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};