/* Daily Question: 2337. Move Pieces to Obtain a String
 * by Tyler Edwards | December 4th, 2024  
 * Code Credit: Siddharth Gangwar
 * You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:
 * - The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
 * - The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
 * Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false. */

class Solution {
public:
    bool canChange(string s, string t) {
        queue<pair<char, int>> ss, ts;
        
        // Fill queue with start
        for(int i=0; i<s.size(); i++){
            if(s[i] != '_')ss.push({s[i], i});        
        }
        
        // Fill queue with target
        for(int i=0; i<t.size(); i++){
            if(t[i] != '_')ts.push({t[i], i});
        }

        if(ss.size() != ts.size())return false;
        
        while(ss.size()){
            pair<char, int> sp, tp;
            
            sp = ss.front();
            tp = ts.front();
            
            ss.pop();
            ts.pop();
            
//             If both the letters don;t match return false, or check for the index to move Left and Right
            if(sp.first != tp.first) return false;
            if(sp.first == 'L' && tp.second>sp.second){
                return false;
            } else if(sp.first == 'R' && tp.second<sp.second){
                return false;
            }
        }
        
        return true;
    }
};