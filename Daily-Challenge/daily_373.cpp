/* Daily Question: 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * by Tyler Edwards | November 30th, 2024  
 * Code Credit: Vlad
 * Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.
 * Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. 
 * If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
 * A prefix of a string s is any leading contiguous substring of s. */

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        auto pos = sent.find(word);
        if (pos != string::npos)
            return count(begin(sent), begin(sent) + pos + 1, ' ');
        return -1;
    }
};