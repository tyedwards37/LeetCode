/* Daily Question: 2579. Count Total Number of Colored Cells
 * by Tyler Edwards | March 4th, 2025 
 * Code Credit: lee
 * There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:
 * - At the first minute, color any arbitrary unit cell blue.
 * - Every minute thereafter, color blue every uncolored cell that touches a blue cell.
 * Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3. */

 class Solution {
    public:
        long long coloredCells(int n) {
            return 1l * n * n + 1l * (n - 1) * (n - 1);
        }
    };