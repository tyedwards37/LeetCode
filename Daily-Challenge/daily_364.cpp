/* Daily Question: 1861. Rotating the Box
 * by Tyler Edwards | November 22nd, 2024  
 * Code Credit: Zhenglai Liu
 * You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
 * - A stone '#'
 * - A stationary obstacle '*'
 * - Empty '.'
 * The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. 
 * Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions. 
 * It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box. 
 * Return an n x m matrix representing the box after the rotation described above. */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size();
        vector<vector<char>> ans(N, vector<char>(M, '.'));
        for (int i = 0; i < M; ++i) {
            int w = N - 1; // `w` is the write pointer
            for (int j = N - 1; j >= 0; --j) {
                if (A[i][j] == '.') continue;
                if (A[i][j] == '#') {
                    ans[w--][M - i - 1] = '#'; // write stone to position `(w, M - i - 1)` and move write pointer
                } else {
                    ans[j][M - i - 1] = '*';
                    w = j - 1; // move the writer pointer to the position after the obstacle
                }
            }
        }
        return ans;
    }
};