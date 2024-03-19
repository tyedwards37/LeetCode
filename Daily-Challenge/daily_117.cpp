/* Daily Question: 621. Task Scheduler
 * by Tyler Edwards | March 18th, 2024 
 * Code Credit: beetlecamera
 * You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. 
 * Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time. 
 * ​Return the minimum number of intervals required to complete all tasks. */

 class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        return max((int)tasks.size(), ans);
    }
};