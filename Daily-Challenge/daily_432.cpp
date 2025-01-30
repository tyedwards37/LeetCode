/* Daily Question: 2493. Divide Nodes Into the Maximum Number of Groups
 * by Tyler Edwards | Janaury 29th, 2025 
 * Code Credit: Mehrab Hossain Opi
 * You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
 * You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
 * Divide the nodes of the graph into m groups (1-indexed) such that:
 * - Each node in the graph belongs to exactly one group.
 * - For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
 * Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions. */

class Solution {
public:
    vector<int>adj[505];
    int col[505];
    int dis[505][505];
    bool flag;
	//nodes in a connected graph.
    vector<int>kara;
	
	//check if graph is bipartite
    void dfs(int u,int c=1){
        col[u] = c;
        kara.push_back(u);
        for(int&v:adj[u]){
            if(!col[v]) dfs(v,3-c);
            else if(col[v]==c)flag = 0;// graph is not bipartite
        }
    }
	//calculate minimum distance between all nodes.
    void bfs(int src){
        for(int i=1;i<=500;i++)dis[src][i] = 100001;
        dis[src][src] = 1;
        queue<int>q;
        q.push(src);
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(int&v:adj[u]){
                if(dis[src][v]>dis[src][u]+1){
                    dis[src][v] = dis[src][u]+1;
                    q.push(v);
                }
            }
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(int i=1;i<=n;i++)adj[i].clear();
        memset(col,0,sizeof col);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i=1;i<=n;i++)bfs(i);
        int ans = 0;
        int in = 0;
        for(int i=1;i<=n;i++){
            if(col[i]==0){
                kara.clear();
                flag = 1;
                in++;
                dfs(i);
                if(!flag) return -1;
                int mxdis = 0;
                for(int&i:kara){
                        for(int&j:kara){
                            mxdis=max(mxdis,dis[i][j]);
                        }
                }
                ans+=mxdis;
            }
        }
        return ans;
    }
};