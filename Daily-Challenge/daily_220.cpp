/* Daily Question: 1550. Three Consecutive Odds
 * by Tyler Edwards | June 30th, 2024
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false. */

 class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int num : arr) {
            if (num % 2 == 0) count = 0;
            else count++;
            if (count == 3) return true;
        }

        return false;
    }
};