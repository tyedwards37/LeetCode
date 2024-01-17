/* Daily Question: 1207. Unique Number of Occurrences
 * by Tyler Edwards | January 17th, 2024 
 * Code Credit: votrubac
 * Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise. */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;

        for (auto n : arr) {
            m[n]++;
        }

        for (auto& i : m) {
            s.insert(i.second);
        }

        return s.size() == m.size();
    }
};