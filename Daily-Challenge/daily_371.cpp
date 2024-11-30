/* Daily Question: 2097. Valid Arrangement of Pairs
 * by Tyler Edwards | November 29th, 2024  
 * Code Credit: Ryan
 * You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.
 * Return any valid arrangement of pairs. */

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m = pairs.size();
        // Eulerian Path
        unordered_map<int, stack<int>> adj;
        unordered_map<int, int> in;
        unordered_map<int, int> out;
		// reserve spaces for unordered_map may help in runtime.
		adj.reserve(m);
		in.reserve(m);
		out.reserve(m);
        for (int i = 0; i < m; i++) {
            int u = pairs[i][0], v = pairs[i][1];
            in[v]++;
            out[u]++;
            adj[u].push(v);
        }
		// find the starting node
        int start = -1;
        for (auto& p : adj) {
            int i = p.first;
            if (out[i] - in[i] == 1) start = i;
        }
        if (start == -1) {
			// Eulerian Circuit -> start at any node
			start = adj.begin()->first;
        }
        vector<vector<int>> ans;
        euler(adj, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void euler(unordered_map<int, stack<int>>& adj, vector<vector<int>>& ans, int curr) {
        auto& stk = adj[curr];
        while (!stk.empty()) {
            int nei = stk.top();
            stk.pop();
            euler(adj, ans, nei);
			// postorder
            ans.push_back({curr, nei});
        }
    }
};