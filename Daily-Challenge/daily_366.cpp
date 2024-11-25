/* Daily Question: 773. Sliding Puzzle
 * by Tyler Edwards | November 24th, 2024  
 * Code Credit: Lakshya Vijh
 * On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
 * The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
 * Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1. */

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0;
        string end = "123450";
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        
        string begin = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                begin+=to_string(board[i][j]);
            }
        }
        unordered_set<string> visited;
        visited.insert(begin);
        queue<pair<string, int>> q;
        q.push({begin, 0});
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            string curr = p.first;
            int dist = p.second;
            int idx = curr.find("0");
            if(curr == end)
                return dist;
            for(auto &i : moves[idx]) {
                string next = curr;
                swap(next[idx], next[i]);
                if(!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
        return -1;
    }
};