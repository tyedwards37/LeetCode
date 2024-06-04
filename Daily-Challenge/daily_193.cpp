/* Daily Question: 409. Longest Palindrome
 * by Tyler Edwards | June 3rd, 2024 
 * Code Credit: _HeLL0____
 * Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome. */

class Solution {
public:
    int longestPalindrome(string s) {
        int oddFrequencyCount = 0; // intialize an integer to track the odd frequency of characters
        unordered_map<char, int> charFrequency; // unordered map to store the number of each character
        for (char ch : s) { // loop for all the characters in the string
            charFrequency[ch]++; // increment the frequency of the given character
            if (charFrequency[ch] % 2 == 1) // checks if the frequency is odd
                oddFrequencyCount++; // increments the odd frequency counter
            else // checks if frequency is even
                oddFrequencyCount--; // decrements the odd frequncy count
        }
        if (oddFrequencyCount > 1) // checks if the odd freqency count is greater than 1
            return s.length() - oddFrequencyCount + 1; // return the length of the string minus the odd frequency count plus one (to make up for the one charcter that can had an odd freq in a palindrome)
        return s.length(); // return the length of the string
    }
};