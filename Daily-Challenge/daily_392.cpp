/* Daily Question: 2872. Maximum Number of K-Divisible Components
 * by Tyler Edwards | December 20th, 2024  
 * Code Credit: Utkarsh Vijay
 * There is an undirected tree with n nodes labeled from 0 to n - 1. 
 * You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
 * You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.
 * A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.
 * Return the maximum number of components in any valid split. */

class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;
    int comp;

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        comp = 0;

        int src = 0;

        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(src, values, k);
        return comp;
    }

private:
    int dfs(int root, vector<int>& values, int k) {
        if (visited.count(root)) {
            return 0;
        }

        visited.insert(root);
        int ans = values[root];

        for (int neigh : adj[root]) {
            ans += dfs(neigh, values, k);
        }

        if (ans % k == 0) {
            comp++;
            return 0;
        }

        return ans % k;
    }
};