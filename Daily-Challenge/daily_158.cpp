/* Daily Question: 2997. Minimum Number of Operations to Make Array XOR Equal to K
 * by Tyler Edwards | April 28th, 2024  
 * Code Credit: shreyanshjn
 * You are given a 0-indexed integer array nums and a positive integer k.
 * You can apply the following operation on the array any number of times:
 * - Choose any element of the array and flip a bit in its binary representation. Flipping a bit means changing a 0 to 1 or vice versa.
 * Return the minimum number of operations required to make the bitwise XOR of all elements of the final array equal to k. */

class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        for (int a : A) { // loop for all of integers in the vector 
            k ^= a; // for each element in a it XORs it with k
        }
        return __builtin_popcount(k); // counts the number of operations neede to convery a to k
    }
};
