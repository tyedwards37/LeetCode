/* Daily Question: 169. Majority Element
 * by Tyler Edwards | February 12th, 2024 
 * Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string ""
 * A string is palindromic if it reads the same forward and backward. */

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int left = 0;
            int right = word.size() - 1;

            while (left <= right) {
                if (word[left] != word[right]) {
                    break;
                }
                left++;
                right--;
            }

            if (left >= right) return word;
        }

        return "";
    }
};