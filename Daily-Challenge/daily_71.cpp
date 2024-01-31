/* Daily Question: 739. Daily Temperatures
 * by Tyler Edwards | January 30th, 2024 
 * Code Credit: riemeltm
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
 * If there is no future day for which this is possible, keep answer[i] == 0 instead. */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>nge(n, 0); 
        stack<int>st{};
        
        for(int i = n - 1; i >= 0; --i){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if(!st.empty())
                nge[i] = st.top()-i; 
                
            st.push(i);
        }
        
        return nge;
    }
};