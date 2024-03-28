/* Daily Question: 2958. Length of Longest Subarray With at Most K Frequency
 * by Tyler Edwards | March 27th, 2024 
 * Code Credit: lee215
 * You are given an integer array nums and an integer k.
 * The frequency of an element x is the number of times it occurs in an array.
 * An array is called good if the frequency of each element in this array is less than or equal to k.
 * Return the length of the longest good subarray of nums.
 * A subarray is a contiguous non-empty sequence of elements within an array. */

class Solution {
public:
        int maxSubarrayLength(vector<int>& A, int k) {
        unordered_map<int, int> freq; // create an unordered map to keep track of frequency of numbers
        int answer = 0, i = 0, n = A.size(); // intialize an answer and left-side window variable to zero, and a variable for the size
         
        for (int j = 0; j < n; ++j) {   // loop for the length of the array
            freq[A[j]]++; // incremenet the frequency of the value at j in the arry 
            while (freq[A[j]] > k) // if the count of the value at j is larger than the max value of k 
                freq[A[i++]]--; // increase left-side of the window by 1 and decrement the count at that value
            answer = max(answer, j - i + 1); // compare the curent value of answer with the size of th window
        }

        return answer; // return the final value of the answer
    }
};