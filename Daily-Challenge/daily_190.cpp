/* Daily Question: 3110. Score of a String
 * by Tyler Edwards | May 31st, 2024
 * You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
 * Return the score of s. */

class Solution {
public:
    int scoreOfString(string s) {
        int answer = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            answer += abs(s[i] - s[i + 1]);
        }

        return answer;
    }
};