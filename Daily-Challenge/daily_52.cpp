/* Daily Question: 739. Daily Temperatures
 * by Tyler Edwards | January 10th, 2024 
 * Code Credit: sparklethinker
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
 * If there is no future day for which this is possible, keep answer[i] == 0 instead. */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int j = i+1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                if (res[j] > 0) j = res[j] + j;
                else j = temperatures.size();
            }
            
            if (j < temperatures.size()) res[i] = j - i;
        }

        return res;
    }
};