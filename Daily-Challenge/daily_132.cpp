/* Daily Question: 79. Word Search
 * by Tyler Edwards | April 3rd, 2024 
 * Code Credit: grandyang
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once. */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) // loops for the size of the board row length
        for (unsigned int j = 0; j < board[0].size(); j++)  // loops for the size of the board col length
            if (dfs(board, i, j, word)) // calls the dfs function with the board, row variable, col variable, and the word to find
                return true; // if the dfs function returns true, return true for the entire thing
    return false; // if route isn't taking, meaning the word is not in the grid 
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size()) // if the size of the string is 0, meaning there's no unfound characters
        return true; // return true if every character has been found
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  // check if the row is within the range of the grid
        return false; // all the characters have not been found and the row / col values are outside of the range, return flase
    char c = board[i][j]; // find the character at the current index of the board using the row and col variables 
    board[i][j] = '*'; // replace the character with an asterisk to show its already been used
    string s = word.substr(1); // reduce the string to a string that only holds the first character
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s); // recursively call dfs and set the bool value 
    board[i][j] = c; // set the value in the board back to its character 
    return ret; // return the final boolean value
}
};