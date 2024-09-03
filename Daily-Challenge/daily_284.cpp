/* Daily Question: 1945. Sum of Digits of String After Convert
 * by Tyler Edwards | September2ndt, 2024 
 * Code Credit: Sachinonly__
 * You are given a string s consisting of lowercase English letters, and an integer k.
 * First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). 
 * Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.
 * For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:
 * - Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
 * - Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
 * - Transform #2: 17 ➝ 1 + 7 ➝ 8
 * Return the resulting integer after performing the operations described above. */

class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character in the string to its corresponding numeric value
        string number = "";
        for (char x : s) {
            number += to_string(x - 'a' + 1);
        }
        
        // Perform the transformation `k` times
        while (k > 0) {
            int temp = 0;
            for (char x : number) {
                temp += x - '0';  // Sum the digits of the current number
            }
            number = to_string(temp);  // Convert the sum back to a string
            k--;
        }
        return stoi(number);  // Return the final result as an integer
    }
};