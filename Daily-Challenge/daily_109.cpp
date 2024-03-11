/* Daily Question: 791. Custom Sort String
 * by Tyler Edwards | March 10th, 2024 
 * Code Credit: lailianqi
 * You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
 * Permute the characters of s so that they match the order that order was sorted. 
 * More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string. 
 * Return any permutation of s that satisfies this property. */

class Solution {
  public:
    string customSortString(string S, string T) {
        unordered_map<char, int> dir;
        for (int i = 0; i < S.size(); i++) {
            dir[S[i]] = i + 1;
        }
        sort(T.begin(), T.end(),
             [&](char a, char b) { return dir[a] < dir[b]; });
        return T;
    }
};