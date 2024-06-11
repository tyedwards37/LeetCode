/* Daily Question: 1122. Relative Sort Array
 * by Tyler Edwards | June 10th, 2024 (Lucky number 200)
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
 * Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order. */

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count = 0, size1 = arr1.size(); // intialize an integer to count the number of swaps and to hold the size of array1

        for (int i = 0; i < arr2.size(); i++) { // loop for each of the values in array2
            for (int j = count; j < size1; j++) { // loop for each of the values in array1, not taking into account values that have alreadey been swapped 
                if (arr2[i] == arr1[j]) { // check if the current array2 value (index i) is the same as the current array1 value (index j)
                    swap(arr1[j], arr1[count]); // swaps the values at the j index and the count index within array1
                    count++; // increments the count to show a swap has occured
                }
            }
        }

        if (count < size1 - ) sort(arr1.begin() + count, arr1.end()); // checks if count is less than the size minus 1 and sorts the last few values

        return arr1; // returns the sorted array1
    }
};