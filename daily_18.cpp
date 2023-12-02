/* Daily Question: 1160. Find Words That Can Be Formed by Characters
 * by Tyler Edwards | December 1st, 2023 
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 * Return the sum of lengths of all good strings in words. */

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int sum = 0;
        int count[26] = {};

        for (auto c : chars)
        {
            ++count[c - 'a'];
        }

        for(auto &word : words)
        {
            int count2[26] = {};
            bool match = true;

            for (auto c : word)
            {
                if (++count2[c - 'a'] > count[c - 'a'])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                sum += word.size();
            }
        }

        return sum;
    }
};