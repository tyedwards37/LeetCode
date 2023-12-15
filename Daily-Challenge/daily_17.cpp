/* Daily Question: 1662. Check If Two String Arrays are Equivalent
 * by Tyler Edwards | November 30th, 2023 
 * Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
 * A string is represented by an array if the array elements concatenated in order forms the string. */

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string firstWord = "";
        string secondWord = "";

        for (int i = 0; i < word1.size(); i++)
        {
            firstWord += word1[i];
        }

        for (int i = 0; i < word2.size(); i++)
        {
            secondWord += word2[i];
        }

        if (firstWord.compare(secondWord) == 0)
        {
            return true;
        }

        return false;
    }
};
