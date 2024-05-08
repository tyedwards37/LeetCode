/* Daily Question: 506. Relative Ranks
 * by Tyler Edwards | May 7th, 2024 
 * Code Credit: sodhanipranav
 * You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
 * The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. 
 * The placement of each athlete determines their rank: 
 * - The 1st place athlete's rank is "Gold Medal".
 * - The 2nd place athlete's rank is "Silver Medal".
 * - The 3rd place athlete's rank is "Bronze Medal".
 * - For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
 * Return an array answer of size n where answer[i] is the rank of the ith athlete. */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int> > pq; // intialize a priority queue 
        for(int i=0;i<nums.size();i++) // loop for the size of the nums vector 
        {
            pq.push(make_pair(nums[i],i)); // order the values
        }
        vector<string> res(nums.size(),""); // make a new answer array of ints
        int count = 1; // intialize an integer for count  to 1 
        for(int i=0; i<nums.size();i++) // loop for the size of nums
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; count++;} // set the value of the biggest value to "Gold Medal"" and increment count"
            else if(count==2) {res[pq.top().second] = "Silver Medal"; count++;} // set the value of the second biggest value to "Silver Medal"" and increment count"
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; count++;} // set the value of the third biggest value to "Bronze Medal"" and increment count"
            else {res[pq.top().second] = to_string(count); count++;} // converts the integer to a string and adds it to the vector
            pq.pop(); // pops that value
        }
        return res; // return the result vector
    }
};