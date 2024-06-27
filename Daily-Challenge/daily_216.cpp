/* Daily Question: 1791. Find Center of Star Graph
 * by Tyler Edwards | June 26th, 2024
 * There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
 * You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph. */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0]|| edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

// Explanation: Checks if the 0th value in the first set of edges in the array matches one of the values in the next set of edges. If it does it returns the 0th value, if not it returns the 1st value.
// Reasoning: The star graph has only one value that is repeated, therefore we take a random set of edges (0th) and compare it with another set of edges (1st) to see what values match up. If it isn't the first value of teh first set of edges, it has to be the second, by nature of the star graph.