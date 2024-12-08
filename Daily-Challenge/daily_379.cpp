/* Daily Question: 2054. Two Best Non-Overlapping Events
 * by Tyler Edwards | December 7th, 2024  
 * Code Credit: innocentCoder
 * You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. 
 * The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. 
 * You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
 * Return this maximum sum.
 * Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. 
 * More specifically, if you attend an event with end time t, the next event must start at or after t + 1. */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int size=e.size(),ans=0,maxi=0;
        sort(e.begin(),e.end());
        map<int,int>mp;
        while(size--){
            auto it=mp.upper_bound(e[size][1]);
            maxi=max(maxi,e[size][2]);
              mp[e[size][0]]=maxi;
            if(it==mp.end())
                ans=max(ans,maxi);
            else
                ans=max(ans,e[size][2]+it->second);
        }
        return ans;
    }
};