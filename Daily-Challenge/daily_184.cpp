/* Daily Question: 140. Word Break II
 * by Tyler Edwards | May 24th, 2024
 * Code Credit: vkg001
 * Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
 * Note that the same word in the dictionary may be reused multiple times in the segmentation. */

class Solution {
    public:
        vector<string> ans;
    
        void solve(int i, string &sentence, string &givenString, unordered_map<string, bool> &doesExist) {
            if (i >= givenString.size()) {
                ans.push_back(sentence);
                return;
            }
    
            for (int j = i + 1; j <= i + 10  &&  j <= givenString.size(); j++) {
                string word = givenString.substr(i, j - i);
                if (doesExist.find(word) != doesExist.end()) {
                    if (sentence.size() == 0) {
                        sentence = word;
                    } else {
                        sentence += " " + word;
                    }
                    solve(j, sentence, givenString, doesExist);
                    int x = 0;
                    while (x < word.size()) {
                        x++;
                        sentence.pop_back();
                    }
    
                    if (sentence.size() > 0) {
                        sentence.pop_back();
                    }
                }
            }
        }
    
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            string sentence = "";
            unordered_map<string, bool> doesExist;
            for (auto x: wordDict) {
                doesExist[x] = true;
            }
    
            ans.clear();
            solve(0, sentence, s, doesExist);
            return ans;
        }
    };