/* LeetCode Day 47: 399. Evaluate Division (Medium) 51/75 
 * Tyler Edwards | December 16th, 2023 
 * Code Credit: iamvinayvk
 * You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
 * Each Ai or Bi is a string that represents a single variable.
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
 * Return the answers to all queries. If a single answer cannot be determined, return -1.0. */

 class Solution {
public:
void dfs(string start,string end,map<string,double>& mp,map<string,vector<string>>& graph,double& val,map<string,int>& visited,bool& found)
{
        visited[start] = 1;
    
        if (found == true)
        {
            return ;
        }

        for (auto child:graph[start])
        {
            if (visited[child] != 1)
            {
                val *= mp[start + "->" + child];
                if (end == child)
                {
                    found = true;
                    return;
                }

                dfs(child, end, mp, graph, val, visited, found);

                if (found == true)
                {
                    return;
                }

                else
                {
                    val /= mp[start + "->" + child];
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        vector<double> answer;
        map<string,double> mp;
        map<string,vector<string>> graph;

        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            mp[u + "->" + v] = values[i];
            mp[v + "->" + u] = 1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            {
                answer.push_back(-1);
            }

            else
            {
                double val = 1;
                map<string,int> visited;
                bool found=false;

                if (start == end)
                {
                    found = true;
                }

                else
                {
                    dfs(start, end, mp, graph, val, visited, found);
                }

                if (found == true)
                {
                    answer.push_back(val);
                }

                else
                {
                    answer.push_back(-1);
                }
                
            }
        }
        return answer;
    }
};