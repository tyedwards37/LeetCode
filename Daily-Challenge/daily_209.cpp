/* Daily Question: 1552. Magnetic Force Between Two Balls
 * by Tyler Edwards | June 19th, 2024
 * Code Credit: alanlzl
 * In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. 
 * Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
 * Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
 * Given the integer array position and the integer m. Return the required force. */

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); // sorts the position array
        int left = 0, right = position.back() - position.front(); // intializes a left and right pointer
        while (left < right) { // loop while the left is less than right
            int mid = right - (right - left) / 2; // find the midpoint of the two values
            if (count(position, mid) >= m) // checks if the count is greater than or equal to the number of balls by calling a user defined function count with the position array and the mid value
                left = mid; // set the left pointer to the mid value
            else // if the count is less than the number of balls
                right = mid - 1; // set the right pointer to the mid value minus one
        }
        return left; // return the final left value after the loops
    }
private:
    int count(vector<int>& position, int d) {
        int ans = 1, cur = position[0]; // intializes an answer integer to 1 and a current integer to the first value in the position array
        for (int i = 1; i < position.size(); ++i) { // loop for the size of the position array minus 1 and starting at index 1 
            if (position[i] - cur >= d) { // checks if the value at the current index of the position array minus the stored current value is greater than or equal to the given d value
                ans++; // increments the answer variable
                cur = position[i]; // sets the current integer to the value of position at index i
            }
        }
        return ans; // return the final answer value
    }
};