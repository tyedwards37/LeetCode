/* Daily Question: 1051. Height Checker
 * by Tyler Edwards | June 9th, 2024 
 * A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. 
 * Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
 * You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed). 
 * Return the number of indices where heights[i] != expected[i]. */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected; // intializes a new array to hol dthe expected order by sorted heights
        expected = heights; // copies the values of heights into expected array
        sort(expected.begin(), expected.end()); // sorts the expected array by height in decreasing order

        int result = 0; // intializes an int for the amount of incides that do not match from hieghts to expected
        for(int i = 0; i < heights.size(); i++) { // loop for the nnumber of values in the arrays 
            if(heights[i] != expected[i]) result++; // check if the values are not the same then if they aren't increment the results variable
        }

        return result; // return the final value of the results variable after the loops
    }
};