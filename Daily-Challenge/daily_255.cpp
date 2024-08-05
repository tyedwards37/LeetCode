/* Daily Question: 2053. Kth Distinct String in an Array
 * by Tyler Edwards | August 4th, 2024 
 * Code Credit: kartikdevsharmaa
 * A distinct string is a string that is present only once in an array.
 * Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
 * Note that the strings are considered in the order in which they appear in the array. */

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinct, seen;
        for (const string& str : arr) {
            if (!seen.insert(str).second) {
                distinct.erase(str);
            } else {
                distinct.insert(str);
            }
        }
        for (const string& str : arr) {
            if (distinct.count(str) && --k == 0) {
                return str;
            }
        }
        return "";
    }
};