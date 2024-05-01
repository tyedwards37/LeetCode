/* Daily Question: 2000. Reverse Prefix of Word
 * by Tyler Edwards | April 30th, 2024  
 * Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). 
 * If the character ch does not exist in word, do nothing.
 * - For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
 * Return the resulting string. */

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); i++) { // loop for the size of the word string
            if(word[i] == ch) { // check if character at the current index of the given word string is equal to the character we are searching for 
                reverse(begin(word), begin(word) + i + 1); // reverses the chunk of the string and appends it back
                break; // breaks out of the loop now that the targeted part of the string has been reversed
            }
        }

        return word; // return the altered word
    }
};