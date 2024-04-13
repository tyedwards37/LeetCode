/* Daily Question: 85. Maximal Rectangle
 * by Tyler Edwards | April 11th, 2024 
 * Code Credit: mcrystal
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0; // check if the matrix is empty and if it is return 0 because there are no 1s
        const int m = matrix.size(); // get an int that represents the number of rows within the matrix
        const int n = matrix[0].size(); // get an int that represents the number of cols within the matrix
        int left[n], right[n], height[n]; // intialize three arrays of ints
        fill_n(left, n, 0); fill_n(right, n, n); fill_n(height, n, 0); // fills the array with n of values 
        int maxA = 0; // intialize a max variable to 0
        for(int i = 0; i < m; i++) { // loops for the number of rows 
            int cur_left = 0, cur_right = n; // intialize a current left and right pointer variable
            for(int j = 0; j < n; j++) {  // loops for the number of cols
                if(matrix[i][j]=='1') height[j]++; // increments to calculate the height
                else height[j] = 0; // sets the value at the index j to 0 
            }
            for(int j = 0; j < n; j++) { // loops for the number of cols
                if(matrix[i][j]=='1') left[j]=max(left[j],cur_left); // computes the left value at index j if the value at the matrix is equal to 1
                else {left[j]=0; cur_left=j+1;} // computes the left value at index j if the value at the matrix is not equal to 1
            }
         
            for(int j = n - 1; j >= 0; j--) { // loops for the number of cols starting at the max index 
                if(matrix[i][j]=='1') right[j]=min(right[j],cur_right); // computes the right value at index j if the value at the matrix is equal to 1
                else {right[j]=n; cur_right=j;} // computes the right value at index j if the value at the matrix is not equal to 1   
            }
            
            for(int j = 0; j < n; j++) // loops for the amount of rows in the matrix
                maxA = max(maxA,(right[j]-left[j])*height[j]); // find the max values
        }
        return maxA; // return the max value
    }
};