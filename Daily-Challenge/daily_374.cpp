/* Daily Question: 2109. Adding Spaces to a String
 * by Tyler Edwards | December 2nd, 2024  
 * Code Credit: Zhenglai Liu
 * You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. 
 * Each space should be inserted before the character at the given index.
 * - For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
 * Return the modified string after the spaces have been added. */

class Solution {
public:
    string addSpaces(string s, vector<int>& A) {
        string ans;
        ans.reserve(s.size() + A.size()); // Optional: pre-allocate enough space for the answer.
        int N = s.size(), j = 0, M = A.size(); // `A[j]` is the next index before which a space should be inserted
        for (int i = 0; i < N; ++i) {
            if (j < M && i == A[j]) { // If `i == A[j]`, we insert a space
                ans += ' ';
                ++j;
            }
            ans += s[i];
        }
        return ans;
    }
};