/* Daily Question: 1482. Minimum Number of Days to Make m Bouquets
 * by Tyler Edwards | June 18th, 2024 
 * Code Credit: lancertech6
 * You are given an integer array bloomDay, an integer m and an integer k.
 * You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
 * The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
 * Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1. */

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) { // check that the given m and k multiplied together are not greater than the size of the bloom day array
            return -1; // return -1 for edge case
        }

        int low = 1, high = 1e9; // intialize two integers for the high and low pointers making them 1 and 1e9 respectively
        while (low < high) { // loop while the low is less than the high
            int mid = low + (high - low) / 2; // finds the midpoint between the two points

            if (canMakeBouquets(bloomDay, m, k, mid)) { // calls the canMakeBouquets function with the given array, values, and the midpoint and checks if its true
                high = mid; // set the high value to the mid value
            } else { // if the function returns false
                low = mid + 1; // sets low to the mid value plus 1 
            }
        }

        return low; // return the final low value
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) { 
        int total = 0; // intializes an integer to the hold the total to 0
        for (int i = 0; i < bloomDay.size(); i++) { // loop for all the values in the bloom day array 
            int count = 0; // intialize an integer to hold the count for the given index i 
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) { // loop while the index is lower than the size of the array, the count is less than the given k value, and the currente value of the bloomday array is less than or equal to the given day value
                count++; // increment the count variable
                i++; // increment the index 
            }

            if (count == k) { // checks if count is equal to the given k
                total++; // increments the total
                i--; // decrements the index i
            }

            if (total >= m) { // checks if the total is greater than or equal to the given m value
                return true; // returns true
            }
        }

        return false; // gone through all the loops without triggering the true conditional, means that it returns false
    }
};