/* Daily Question: 2418. Sort the People
 * by Tyler Edwards | July 21st, 2024 
 * Code Credit: kiranpalsingh1806
 * You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
 * For each index i, names[i] and heights[i] denote the name and height of the ith person.
 * Return names sorted in descending order by the people's heights. */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string>mp;
        vector<string>v;
        for(int i=0; i < size(names); i++)
            mp[heights[i]] = names[i];
        for (auto i = mp.rbegin(); i != mp.rend(); ++i) v.push_back(i->second);
        return v;
    }
};