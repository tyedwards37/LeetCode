/* Daily Question: 1400. Construct K Palindrome Strings
 * by Tyler Edwards | Janaury 10th, 2025 
 * Code Credit: lee
 * Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise. */

class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for (char& c : s)
            odd.flip(c - 'a');
        return odd.count() <= k && k <= s.length();
    }
};