/* Daily Question: 2185. Counting Words With a Given Prefix
 * by Tyler Edwards | Janaury 8th, 2025 
 * Code Credit: Tarun Sahnan
 * You are given an array of strings words and a string pref.
 * Return the number of strings in words that contain pref as a prefix.
 * A prefix of a string s is any leading contiguous substring of s. */

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int count=0;
        int preflen=pref.size();        //step 1
        
        for(auto i:words){
            if(i.substr(0,preflen) == pref)     //step 2
                count++;                        //if both matches then increment count by 1
            
        }
        return count;   //return count
        
    }
};