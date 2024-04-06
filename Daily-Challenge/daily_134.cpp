/* Daily Question: 1544. Make The String Great
 * by Tyler Edwards | April 4th, 2024 
 * Code Credit: ayushsingh1081
 * Given a string s of lower and upper case English letters.
 * A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
 * - 0 <= i <= s.length - 2
 * - s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
 * To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
 * Return the string after making it good. The answer is guaranteed to be unique under the given constraints. */

class Solution {
public:
    string makeGood(string s) {
        string answer; // create a string for the answer
        for(int i = 0 ; i < s.size() ; i++) { // loop for the length of the given string
            answer.push_back(s[i]); // push the current character back on the answer string
            while(answer.size() && (answer.back()==s[i+1]+32 || answer.back()==s[i+1]-32)) { // loop for given conditions and there is characters left in answer
                answer.pop_back(); // pop the last character
                i++; // iterate through i 
            }
        }
        
        return answer; // return the answer variable
    }
};
