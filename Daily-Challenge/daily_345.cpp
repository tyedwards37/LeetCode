/* Daily Question: 796. Rotate String
 * by Tyler Edwards | November 3rd, 2024 
 * Code Credit: dnuang
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * - For example, if s = "abcde", then it will be "bcdea" after one shift. */

class Solution {
public:
    bool rotateString(string A, string B) {                
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }    
};