/* Daily Question: 1514. Path with Maximum Probability
 * by Tyler Edwards | August 30th, 2024 
 * Code Credit: uds5501
 * You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
 * Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
 * If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5. */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], pro[i]});
            g[edges[i][1]].push_back({edges[i][0], pro[i]});   
        }
        vector<int> seen(n, 0);
        
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        
        vector<double> mx(n, (double)0.0);
        mx[start] = 1.0;
        
        while(!q.empty()) {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int node = top.second;
            if(!seen[node]) {
                seen[node]++;
                for(auto &to: g[node]) {
                    if (mx[to.first] < to.second*proba) {
                        mx[to.first] = to.second*proba;
						q.push({mx[to.first], to.first});
                    }
                }
            }
        }
        return mx[end];
    }
};