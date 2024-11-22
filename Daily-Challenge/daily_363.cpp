/* Daily Question: 1072. Flip Columns For Maximum Number of Equal Rows
 * by Tyler Edwards | November 21st, 2024  
 * Code Credit: Sourov Roy
 * You are given an m x n binary matrix matrix.
 * You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
 * Return the maximum number of rows that have all values equal after some number of flips. */

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> hmap;
        for(auto x: matrix){
            string s=""; 
            //s keeps track of relative ordering of elements in a row w.r.t the first element
            int top=x[0];
            for(int i=0;i<x.size();i++){
                if(x[i]==top)
                    s+='1';
                else
                    s+='0';
            }
            hmap[s]++; 
        }
        
        int result=0;
        for(auto &[key,val]:hmap)
            result=max(result,val); 
        //rows that have identical relative ordering, can be simultaneously toggled columnwise in order to make all
        //elements of any of those rows unique. So the answer is maximum number of rows with identical relative ordering.
        return result;
    }
};