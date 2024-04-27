/* Daily Question: 514. Freedom Trail
 * by Tyler Edwards | April 26th, 2024  
 * Code Credit: yangyx
 * In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.
 * Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.
 * Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.
 * At the stage of rotating the ring to spell the key character key[i]:
 * 1. You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
 * 2. If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling. */

 class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int size = ring.size(); // intializes an int to the size of the ring string
        int ksize = key.size(); // intializes an int to the size of the ket string
        vector<vector<int>> mp(26);   // intialize a vector with a size of 26 for all the possible characters 
        for(int i=0;i<size;++i){ // loop for the size of the ring
            mp[ring[i]-'a'].push_back(i); // at index of the character value at i of ring, push back the value of mp
        }
        
        vector<int> dp (size,INT_MAX);   // intialize a 2D vector of min size "size" and max of INT_MAX
        dp[0] = 0; // set the value at index 0 to 0
        
        vector<int> startIndex(1,0); // starting index of the vector

        for(int i=1;i<=ksize;++i){ // loop for the size of the key
            vector<int> nextDp(size,INT_MAX); //  intialize another 2D vecotr with the same size parameters as the first
            for(auto it:mp[key[i-1]-'a']){ // loop for the values in mp
                for(int j=0;j<startIndex.size();++j){ // loop for the size of the start index vector
                    int minDist = min((startIndex[j] + size -it)%size,(it + size - startIndex[j])%size) + dp[startIndex[j]]; // allows for rotating the ring
                    nextDp[it] =min(nextDp[it],minDist); // sets teh value at index it to the min of minDist and the current value in nextDp at that value
                }
            }
            startIndex = mp[key[i-1]-'a']; // set startIndex to the value at the previous i value of key of map
            dp = nextDp; // set dp equal to nextDp
        }
        
        int res = INT_MAX; // intialize and answer integer to INT_MAX
        for(int i=0;i<size;++i){ // loop for size 
            res = min(res,dp[i]); // set the answr value to teh smallest value betwen itself and each value fo dp
        } 
        
        return res + ksize; // return that final smallest value + the size of the key
    }
};