/* Daily Question: 1653. Minimum Deletions to Make String Balanced
 * by Tyler Edwards | July 29th, 2024 
 * Code Credit: himsingh11
 * You are given a string s consisting only of characters 'a' and 'b'​​​​.
 * You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
 * Return the minimum number of deletions needed to make s balanced. */

class Solution {
public:
    //Idea is to traverse from right to left & use stack to keep track if 'b' comes before 'a' in string
    //then we need to pop & need to delete that character
    int minimumDeletions(string s) {
        stack<char> st;
        int n =s.size();
        int res = 0;
        
        for(int i = n-1; i >=0; i--){
            char c = s[i];
            if(!st.empty() && st.top() < c){
                res++;
                st.pop();
            }else{
                st.push(c);
            }
        }
        
        return res;
    }
};