/* Daily Question: 1750. Minimum Length of String After Deleting Similar Ends
 * by Tyler Edwards | March 4th, 2024 
 * Code Credit: votrubac
 * Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
 * 1. Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
 * 2. Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
 * 3. The prefix and the suffix should not intersect at any index.
 * 4. The characters from the prefix and suffix must be the same.
 * 5. Delete both the prefix and the suffix.
 * Return the minimum length of s after performing the above operation any number of times (possibly zero times). */

class Solution {
public:
    int minimumLength(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) {
        auto ch = s[i];
        while (i <= j && s[i] == ch)
            ++i;
        while (i < j && s[j] == ch)
            --j;
    }
    return j - i + 1;
    }
};