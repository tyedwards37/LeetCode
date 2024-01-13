/* Daily Question:  1347. Minimum Number of Steps to Make Two Strings Anagram
 * by Tyler Edwards | January 13th, 2024 
 * Code Credit: soumyagarg
 * You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
 * Return the minimum number of steps to make t an anagram of s.
 * An Anagram of a string is a string that contains the same characters with a different (or the same) ordering. */

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        int sum=0;
        for(auto i:s)
            m[i]++;
        for(auto i:t)
            m[i]--;
        for(auto i:m){
            if(i.second<0)
                sum += i.second;
        }
        return abs(sum);
    }
};