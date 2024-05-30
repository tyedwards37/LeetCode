/* Daily Question: 1442. Count Triplets That Can Form Two Arrays of Equal XOR
 * by Tyler Edwards | May 29th, 2024
 * Code Credit: shubham6762
 * Given an array of integers arr.
 * We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
 * Let's define a and b as follows:
 * - a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * - b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 * Note that ^ denotes the bitwise-xor operation.
 * Return the number of triplets (i, j and k) Where a == b. */

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size(); // intialize an integer to the size of the array
        std::vector<int> prefix(n + 1, 0); // intialize an array of integers 

        for (int i = 0; i < n; ++i) { // looop through for the size of the array
            prefix[i + 1] = prefix[i] ^ arr[i]; // set the value of the new array at index i + 1 to the value at index i XOR'd with the value at index i of the given array
        }

        int count = 0; // intialize a count integer
        for (int i = 0; i < n; ++i) { // loop for the size of the given array 
            for (int k = i + 1; k < n; ++k) { // loop a second time for the size of the array 
                if (prefix[i] == prefix[k + 1]) { // check if the value at prefix index i is the same as the value at prfeix index k + 1
                    count += (k - i); // add k minus i to the existing count variable
                }
            }
        }

        return count; // return the final count variable
    }
};