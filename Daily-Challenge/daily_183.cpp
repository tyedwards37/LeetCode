/* Daily Question: 1255. Maximum Score Words Formed by Letters
 * by Tyler Edwards | May 23rd, 2024
 * Code Credit: HithamOmar
 * Given a list of words, list of  single letters (might be repeating) and score of every character.
 * Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
 * It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively. */

class Solution {
public:
    int a[26], b[26], ans = 0; // intialize two veectors for each of the letters and an answer variable set to 0, all outside of the scope of the functions
    void solve(int idx, vector<string>& words, vector<int>& score) {
        if (idx == words.size()) { // checks if the index is the same as the word size (base case)
            int sc = 0; // intialize an int for the temporary score to 0 
            for (int i = 0; i < 26; i++) { // loop for each of the letters
                if (b[i] > a[i])return; // check if the value in b is greater than in a
                sc += score[i] * b[i]; // add to teh current temp score value the value from teh given score array times the value in b for teh index of the current letter
            }
            ans = max(ans, sc); // set the answer to the max between the current answer and the temp score
            return; // returns and ends the function
        }

        solve(idx + 1, words, score); // recusrively call the solve function with index + 1, the given words array, and given score array
        for (auto i : words[idx]) b[i - 'a']++; // for each of the words in the words array increment the value of b at that given index for the given character
        solve(idx + 1, words, score); // recusrively call the solve function with index + 1, the given words array, and given score array
        for (auto i : words[idx]) b[i - 'a']--; // for each of the words in the words array decrement the value of b at that given index for the given character
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto i : letters) a[i - 'a']++; // for each of the letters in the letters array increment the value of a at that given index for the given character
        solve(0, words, score); // call the solve function with a strating index of 0, giving it the provided letters and score array
        return ans; // return the answer, calculated through recursive calls to solve
    }
};