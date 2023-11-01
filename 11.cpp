/* LeetCode Day 9: Number of Recent Calls (Easy) 11/75 
 * by Tyler Edwards | November 1st, 2023 
 * Desc: You have a RecentCounter class which counts the number of recent requests within a certain time frame. RecentCounter() Initializes the counter with zero recent requests.
 * int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds 
 * (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t]. It is guaranteed that every call to ping uses 
 * a strictly larger value of t than the previous call.*/


class RecentCounter {
public:
    #include <queue>

    RecentCounter() 
    {  
        return;
    }
    
    queue<int> pingTimes;
    int ping(int t) 
    {
        pingTimes.push(t);

        while(pingTimes.front() < t - 3000)
        {
            pingTimes.pop();
        }

        return pingTimes.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */