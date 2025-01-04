/* Daily Question: 1930. Unique Length-3 Palindromic Subsequences
 * by Tyler Edwards | Janaury 3rd, 2025 
 * Code Credit: sahil
 * Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
 * Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
 * A palindrome is a string that reads the same forwards and backwards.
 * A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
 * - For example, "ace" is a subsequence of "abcde". */

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<pair<int, int> > v(26, {-1, -1} ); //to store first occurance  and last occurance of every alphabet.
        
        int n = s.length(); //size of the string
        
        for (int i = 0 ; i< n ;i++ ){
            if (v[s[i] - 'a'].first == -1 ) v[s[i] - 'a'].first = i; // storing when alphabet appered first time.
            else v[s[i] - 'a'].second = i; // else whenever it appears again. So that the last occurrence will be stored at last.
        }
        
        int ans = 0 ;
        for (int i = 0 ; i <26 ;i++ ){ //traversing over all alphabets.

            if (v[i].second != -1 ){ //only if alphabet occured second time.
                
                unordered_set<char> st; //using set to keep only unique elements between the range.
                
                for (int x = v[i].first + 1 ; x < v[i].second ; x++ ) st.insert(s[x]); // set keeps only unique elemets.
                    
                ans += ((int)st.size()); // adding number of unique elements to the answer.
            }
        }
        return ans;
        
    }
};