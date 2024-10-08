/* Daily Question: 1813. Sentence Similarity III
 * by Tyler Edwards | October 4th, 2024 
 * Code Credit: k_m_066
 * You are given two strings sentence1 and sentence2, each representing a sentence composed of words. 
 * A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.
 * Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. 
 * Note that the inserted sentence must be separated from existing words by spaces. 
 * For example, 
 * - s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
 * - s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space. 
 * Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false. */

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        string temp = "";
        deque<string>a,b;
        for(char c:s1){
            if(c == ' ') a.push_back(temp),temp = "";
            else temp += c;
        }
        a.push_back(temp),temp = "";
        for(char c:s2){
            if(c == ' ') b.push_back(temp),temp = "";
            else temp += c;
        }
        b.push_back(temp),temp = "";
		// removing common from front
        while(a.size() != 0 && b.size() != 0 && (a.front() == b.front())) a.pop_front(),b.pop_front();
        //removing common from back
		while(a.size() != 0 && b.size() != 0 && (a.back() == b.back())) a.pop_back(),b.pop_back();
		if(a.size() == 0 || b.size() == 0) return true;
        return false;
    }
};