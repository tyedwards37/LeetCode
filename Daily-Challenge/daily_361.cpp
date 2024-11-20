/* Daily Question: 2516. Take K of Each Character From Left and Right
 * by Tyler Edwards | November 19th, 2024  
 * Code Credit: Prateek
 * You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. 
 * Each minute, you may take either the leftmost character of s, or the rightmost character of s.
 * Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character. */

class Solution {
public:
    int takeCharacters(string s, int k) {
        int ca=0,cb=0,cc=0;
        int n=s.size();
        int ans=n;
        for(int i=0;i<n;i++){
            if(s[i]=='a') ca++;
            if(s[i]=='b') cb++;
            if(s[i]=='c') cc++;
        }
        if(ca<k||cb<k||cc<k) return -1;
        int i=n-1,j=n-1;
        while(i>=0){
            if(s[i]=='a') ca--;
            if(s[i]=='b') cb--;
            if(s[i]=='c') cc--;
            while(ca<k||cb<k||cc<k){
            if(s[j]=='a') ca++;
            if(s[j]=='b') cb++;
            if(s[j]=='c') cc++;
                j--;
            }
            ans=min(ans,i+n-1-j); i--;
        }
        return ans;
    }
};