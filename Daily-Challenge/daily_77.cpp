/* Daily Question: 451. Sort Characters By Frequency
 * by Tyler Edwards | February 6th, 2024 
 * Code Credit: RushRab
 * Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
 * Return the sorted string. If there are multiple answers, return any of them. */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size() + 1, "");
        string res;
        
        for(char c:s) freq[c]++;

        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }

        for(int i = s.size(); i > 0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};