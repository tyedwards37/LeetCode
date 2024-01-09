/* LeetCode Day 65: 435. Non-overlapping Intervals (Medium) 72/75 
 * Tyler Edwards | January 8th, 2024 
 * Code Credit: rahulvarma5297
 * Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping. */

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0;
        int count = 1;

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};