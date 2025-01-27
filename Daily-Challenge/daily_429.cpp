/* Daily Question: 1462. Course Schedule IV
 * by Tyler Edwards | Janaury 26th, 2025 
 * Code Credit: shield75_
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
 * - For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
 * You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
 * Return a boolean array answer, where answer[j] is the answer to the jth query. */
 
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<bool> ans;
    vector<vector<int>> graph(n);   
    vector<vector<bool>> table(n,vector<bool>(n,false));
    vector<int> indegree(n,0);
    for(int i=0;i<prerequisites.size();i++)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto &it:graph[cur])
        {
            table[cur][it]=true;
            for(int i=0;i<n;i++) if(table[i][cur]==true) table[i][it] = true;
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    for(int i=0;i<queries.size();i++) ans.push_back(table[queries[i][0]][queries[i][1]]);
    return ans;
    }
};