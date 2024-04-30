/* Daily Question: 1915. Number of Wonderful Substrings
 * by Tyler Edwards | April 29th, 2024  
 * Code Credit: PhoenixDD
 * A wonderful string is a string where at most one letter appears an odd number of times.
 * - For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
 * Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. 
 * If the same substring appears multiple times in word, then count each occurrence separately.
 * A substring is a contiguous sequence of characters in a string. */

 class Solution {
public:
    int getHash(char &c) {
        return 1<<(c-'a'); // Returns the set bit for a character.
    }
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> count={{0,1}}; // Stores prefix parities.
		int running=0; // intialize int to store running
        long long result=0; // intialize a long long for the result
        for(char &w:word) { // loop for characters in word
            running^=getHash(w); // Update the running parity
			
            for(char c='a';c<='j';c++) // check all posible characters 
                result+=count[running^getHash(c)]; // adds count of substring with at most character 'c' of odd counts
				
            result+=count[running]; // Add counts of substrings with all characters with even counts
			
            count[running]++; // Update the counts for next future iterations.
        }
        return result; // return the answer variable
    }
};