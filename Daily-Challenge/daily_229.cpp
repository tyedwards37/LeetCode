/* Daily Question: 1598. Crawler Log Folder
 * by Tyler Edwards | July 9th, 2024 
 * The Leetcode file system keeps a log each time some user performs a change folder operation.
 * The operations are described below:
 * - "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
 * - "./" : Remain in the same folder.
 * - "x/" : Move to the child folder named x (This folder is guaranteed to always exist).
 * You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.
 * The file system starts in the main folder, then the operations in logs are performed.
 * Return the minimum number of operations needed to go back to the main folder after the change folder operations. */

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int minOps = 0; // intialize an integer to hold the min number of operations to get back to the root

        for (auto log : logs) { // loop for each of the strings in the array
            if(log == "../") minOps = max(0, minOps - 1); // check if the string sends the user back to teh root folder and if it does, find the max between the current minOps - 1 and 0
            else if (log != "./") minOps++; // if the string isn't "../" or "./" that means it adds one layer of depth so you increment the minOps
        }

        return minOps; // return the minOps integer, holding the minimum operations
    }
};