/* Daily Question: 1289. Minimum Falling Path Sum II
 * by Tyler Edwards | April 25th, 2024  
 * Code Credit: votrubac
 * Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
 * A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column. */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
    int fm = 0, sm = 0, pos = -1; // intialize three vairables with two starting at 0 and one at -1
    for (auto i = 0; i < arr.size(); ++i) { // loop for the row size of the array using auto
        auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1; // intialize three auto variables two to INT_MAX and the other to -1
        for (auto j = 0; j < arr[i].size(); ++j) { // loop for the col size of the array using auto
            auto mn = j != pos ? fm : sm; // intialize another auto to fm or sm depending on if mn is not equal to j
            if (arr[i][j] + mn < fm2) { // checks if the current value plus mn is less than fm2
                sm2 = fm2; // sets sm2 to fm2
                fm2 = arr[i][j] + mn; // sets fm2 to the current index value + mv
                pos2 = j; // sets pos2 to j
            } else sm2 = min(sm2, arr[i][j] + mn); // sets sm2 to the minimum between the current sm2 and the current index value + mn
        }
        fm = fm2, sm = sm2, pos = pos2; // sets fm to fm2, sm to sm2, and pos to pos2
    }
    return fm; // return the fm variable
}
};
