/* Daily Question: 983. Minimum Cost For Tickets
 * by Tyler Edwards | December 30th, 2024 
 * Code Credit: Dennis Min
 * You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
 * Train tickets are sold in three different ways:
 * - a 1-day pass is sold for costs[0] dollars,
 * - a 7-day pass is sold for costs[1] dollars, and
 * - a 30-day pass is sold for costs[2] dollars.
 * The passes allow that many days of consecutive travel.
 * - For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
 * Return the minimum number of dollars you need to travel every day in the given list of days. */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> tickets;
        tickets[1] = costs[0];
        tickets[7] = costs[1];
        tickets[30] = costs[2];
        
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<366; ++i){
            if(find(days.begin(), days.end(), i) == days.end()){
                dp[i] = dp[i-1];
                continue;
            }
            for(auto ticket : tickets){
                dp[i] = min(dp[i], dp[max(0, i-ticket.first)] + ticket.second);
            }
        }
        
        return dp[365];
    }
};