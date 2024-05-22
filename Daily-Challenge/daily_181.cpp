/* Daily Question: 131. Palindrome Partitioning
 * by Tyler Edwards | May 21st, 2024
 * Code Credit: ezspeed
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s. */

 class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret; // intialize 2D array of strings to return
        if(s.empty()) return ret; // ends recursive call by checking if the string is empty and returning the final version of the ret array
        
        vector<string> path; // intialize array of strings to recrod the path
        dfs(0, s, path, ret); // cal the depth first search algorithm with 1, the given string, the given path so far, and the return array
        
        return ret; // return the final version of the array 
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) { // checks if the index is equal to the size of the string
            ret.push_back(path); // pushes the path back to the return array 
            return; // ends the loop
        }
        for(int i = index; i < s.size(); ++i) { // loops for the size of the string, given a starting index of i
            if(isPalindrome(s, index, i)) { // checks if the string is a palindrome, given the index and the current i 
                path.push_back(s.substr(index, i - index + 1)); // pushes the substring starting from the current index to the index of i - index + 1 to the path
                dfs(i+1, s, path, ret); // recurisvely calls the dfs algorithm with i+1 as the new index
                path.pop_back(); // pops the back value of path
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) { // checks to make sure the start and end index aren't the same
            if(s[start++] != s[end--]) // checks if the characters on the left and right are the same
                return false; // returns false (not a palindrome)
        }
        return true; // didn't ever reach condition so it returns true (is a palindrome)
    }
};