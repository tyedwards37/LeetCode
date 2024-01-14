/* Daily Question: 1657. Determine if Two Strings Are Close
 * by Tyler Edwards | January 14th, 2024 
 * Code Credit: suman_buie
 * Two strings are considered close if you can attain one from the other using the following operations:
 * - Operation 1: Swap any two existing characters.
 * - Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
 * You can use the operations on either string as many times as necessary.
 * Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise. */

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1(26, 0), w2(26, 0);
        set<char> s1, s2;

        for (char c: word1) {
            w1[c - 'a']++;
            s1.insert(c);
        }

        for (char c : word2) {
            w2[c - 'a']++;
            s2.insert(c);
        }

        sort(begin(w1), end(w1));
        sort(begin(w2), end(w2));

        return w1 == w2 && s1 == s2;
    }
};