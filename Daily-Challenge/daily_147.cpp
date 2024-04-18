/* Daily Question: 463. Island Perimeter
 * by Tyler Edwards | April 17th, 2024 
 * You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally). 
 * The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
 * The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. 
 * The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island. */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0; // intialize a variable to hold the perimeter value
        for (int i = 0; i < grid.size(); i++) { // loop for the row size of the grid
            for (int j = 0; j < grid[0].size(); j++) { // loop for the col size of the grid
                if(grid[i][j] == 1) { // checks if the grid spot is land
                    perimeter += 4; // add four for the sides of the grid
                    
                    if(i > 0 && grid[i - 1][j] == 1) { // checks if the spot to the left is part of the island or a border
                        perimeter--; // subtract by 1 since it borders another island
                    }

                    if(i + 1 < grid.size() && grid[i + 1][j] == 1) { // checks if the spot to the right is part of the island or a border
                        perimeter--; // subtract by 1 since it borders another island
                    }

                    if(j > 0 && grid[i][j - 1] == 1) { // checks if the spot underneath is part of the island or a border
                        perimeter--; // subtract by 1 since it borders another island
                    }

                    if(j + 1 < grid[i].size() && grid[i][j + 1] == 1) { // checks if the spot above is part of the island or a border
                        perimeter--; // subtract by 1 since it borders another island
                    }
                }
            }   
        }

      return perimeter;  // return the variable for the total perimeter value
    }
};
