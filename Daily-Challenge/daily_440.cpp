/* Daily Question: 3160. Find the Number of Distinct Colors Among the Balls
 * by Tyler Edwards | February 6th, 2025 
 * Code Credit: Shubham Baban Shinde
 * You are given an integer limit and a 2D array queries of size n x 2. 
 * There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. 
 * For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls. 
 * Return an array result of length n, where result[i] denotes the number of distinct colors after ith query. 
 * Note that when answering a query, lack of a color will not be considered as a color. */

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;
        for(auto &q : queries) {
            int pos = q[0], c = q[1];
            if(ball.count(pos))
                if(--color[ball[pos]] == 0) distinct--;
            ball[pos] = c;
            if(++color[c] == 1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};