/* Daily Question: 1791. Find Center of Star Graph
 * by Tyler Edwards | June 26th, 2024
 * Code Credit: surajthapliyal
 * There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
 * You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph. */

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0, x = 1;
        vector<int> degree(n,0);
        for(auto road : roads){
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(),degree.end());
        for(auto i : degree) ans += i * (x++);
        return ans;
    }
};