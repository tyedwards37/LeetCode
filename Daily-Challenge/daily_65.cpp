/* Daily Question: 1143. Longest Common Subsequence
 * by Tyler Edwards | January 24th, 2024 
 * Code Credit: rajat_gupta_
 * Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
 * A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
 * A common subsequence of two strings is a subsequence that is common to both strings. */

class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2,int m,int n,int memo[][1001]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+longestCommonSubsequence(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(longestCommonSubsequence(text1,text2,m-1,n,memo),longestCommonSubsequence(text1,text2,m,n-1,memo));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        int memo[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
        return longestCommonSubsequence(text1,text2,m,n,memo);
    }
};