/* Daily Question: 1992. Find All Groups of Farmland
 * by Tyler Edwards | April 19th, 2024 
 * Code Credit: Mazhar_MIK
 * You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.
 * To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. 
 * No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.
 * land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). 
 * Find the coordinates of the top left and bottom right corner of each group of farmland. 
 * A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].
 * Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. 
 * You may return the answer in any order. */

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(); // intialize a variable for the number of rows
        int n = land[0].size(); // intialize a variable for the number of cols
        
        vector<vector<int>> result; // intialize an array of ints to hold the answer
        for(int i = 0; i < m; i++) { // loop for the number of rows
            for(int j = 0; j<n; j++) { // loop for the number of cols
                
                if(land[i][j] == 0) continue; // check for a zero at the current index

                //Find right most column of rectangle 
                int c1 = j; // intialize a variable to start at the current col and increment
                while(c1 < n && land[i][c1] == 1) { // loop while the the value at the row index and the temp col index is equal to 1
                    c1++; // increment the temp col value by 1 
                }

                //Find bottom most row of rectangle
                int r2 = i; // intialize a variable to start at the current row and increment
                while(r2 < m && land[r2][j] == 1) { // loop while the the value at the col index and the temp tow index is equal to 1
                    r2++; // increment the temp row value by 1 
                }
                
                //Then you can find bottom right most of rectangle
                c1 = c1 == 0 ? c1 : c1 - 1; // gets the value of the rightmost col of the rectangle
                r2 = r2 == 0 ? r2 : r2 - 1; // gets the value of the bottom row of the rectangle

                //Use them as your answer
                //{r1, c1} = {i, j}
                //{r2, c2} = {r2, c1}
                result.push_back({i, j, r2, c1}); // push back the found values along wih the current index
                
                //Now, mark the covered land with 0 so that you don't consider them later
                for(int k = i; k <= r2; k++) { // loop through the space of the rectangle (for rows)
                    for(int l = j; l<=c1; l++) { // loop through the space of the rectangle (for cols)
                        land[k][l] = 0; // turn the values at these indexes to 0 
                    }
                }
                
            }
        }
        return result; // return teh final array
    }
};