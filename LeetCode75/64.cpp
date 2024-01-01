/* LeetCode Day 58: 790. Domino and Tromino Tiling (Medium) 64/75 
 * Tyler Edwards | December 31st, 2023 (3... 2... 1...)
 * Code Credit: Shailesh0302
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
 * Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 10^9 + 7.
 * In a tiling, every square must be covered by a tile. 
 * Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile. */

class Solution {
public:
    int mod = 1e9+7;
    long helper(int n, vector<long>& dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        if(dp[n]!=-1) return dp[n]%mod;

        long smallAns1=0, smallAns2=0;
        smallAns1=helper(n-1,dp)%mod;
        smallAns2=helper(n-3,dp)%mod;

        dp[n]=(smallAns1*2+smallAns2)%mod;
        return dp[n]%mod;
    }
    
    int numTilings(int n) {
        vector<long> dp(n+1,-1);
        long ans=helper(n,dp)%mod;
        return (int)ans;        
    }
};
