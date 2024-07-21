/* Daily Question: 2392. Build a Matrix With Conditions
 * by Tyler Edwards | July 20th, 2024 
 * Code Credit: Code-O-Maniac
 * You are given a positive integer k. You are also given: 
 * - a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
 * - a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
 * The two arrays contain integers from 1 to k.
 * You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
 * The matrix should also satisfy the following conditions:
 * - The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
 * - The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
 * Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix. */

class Solution {
    
    /* 1. Checking if cycle is present - If YES, Topological Sort is not possible */
    vector<char> color;
    bool dfs(int v, vector<vector<int>>& graph) {
        color[v] = 1;
        for (int u : graph[v]) {
            if (color[u] == 0) {
                if (dfs(u, graph))
                    return true;
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
    bool find_cycle(vector<vector<int>>& graph, int n) {
        color.assign(n, 0);

        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(v, graph))
                return true;
        }
        return false;
    }

    /* 2. Forming the Topological Sort for DAG */
    vector<bool> visited;
    void dfs2(int v, vector<vector<int>>& graph, vector<int>& ans) {
        visited[v] = true;
        for (int u : graph[v]) {
            if (!visited[u])
                dfs2(u, graph, ans);
        }
        ans.push_back(v);
    }

    void topological_sort(vector<vector<int>>& graph, int n, vector<int>& ans) {
        visited.assign(n, false);
        ans.clear();
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs2(i, graph, ans);
        }
        reverse(ans.begin(), ans.end());
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> graph1(k);
        vector<vector<int>> graph2(k);
        
        for(auto x:rowConditions) {
            graph1[x[0] - 1].push_back(x[1] - 1);
        }
        for(auto x:colConditions) {
            graph2[x[0] - 1].push_back(x[1] - 1);
        }
        
        /* 3. Check if CYCLE present in any of the graphs */
        if(find_cycle(graph1, k) || find_cycle(graph2, k)) return vector<vector<int>>();
        
        /* 4. Forming Topological Sort for the DAGs */
        vector<int> ans1; vector<int> ans2;
        
        topological_sort(graph1, k, ans1);
        topological_sort(graph2, k, ans2);
        
        /* 5. Forming the answer from the rowPosition and colPosition for each element */
        vector<vector<int>> ans(k, vector<int>(k));
        
        map<int, int> m;
        for(int i = 0; i < k; i++) {
            m[ans2[i]] = i;
        }
        
        for(int i = 0; i < k; i++) {
            ans[i][m[ans1[i]]] = ans1[i] + 1;
        }
        
        return ans;
    }
};