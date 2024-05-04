/* Daily Question: 881. Boats to Save People
 * by Tyler Edwards | May 3rd, 2024  
 * Code Credit: hi-malik
 * You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. 
 * Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
 * Return the minimum number of boats to carry every given person. */

 class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            int boatCount = 0; // intialize an int to count the boats
            sort(people.begin(), people.end()); //  sort the array of people 
            
            int left = 0; // make an int to be the left pointer
            int right = people.size() - 1; // make an int to be the right pointer
            
            while(left <= right){ // loop while left is less or equal to right
                int sum = people[left] + people[right]; // set the sum to the weight of person at the index of left + the weight of the person at the eindex of right 
                if(sum <= limit){ // check if the sum is less than or equal to the limit 
                    boatCount++; // increment the number of boats by one
                    left++; // move the left pointer one index right (increment)
                    right--; // move the right pointer one index left (decrement)
                }
                else{ // if the sum is greater than the limit
                    boatCount++; // increment the number of boats 
                    right--;  // move the right pointer one index left (decrement)
                }
            }
            return boatCount; // return the final number of boats
        }
    };