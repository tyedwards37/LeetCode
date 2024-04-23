/* Daily Question: 310. Minimum Height Trees
 * by Tyler Edwards | April 21st, 2024 
 * Code Credit: shtanriverdi    
 * A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. 
 * When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
 * Return a list of all MHTs' root labels. You can return the answer in any order.
 * The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf. */

 class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) // if the tree has no nodes 
            return {}; // return an empty list
        if(n==1) // if the tree only has one node
            return {0}; // return a list with only the root node
        vector<int>res; // create an array of ints for the answer
        vector<int>degrees(n,0); // create another array of ints with parameters of n and 0
        vector<vector<int>>adj(n); // create an array of arrays for adjacency with the parameter n
        for(int i=0;i<edges.size();i++) // loop for the number of edges 
        {
            adj[edges[i][0]].push_back(edges[i][1]); //creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]); // pushes back another edge to the adjacency list
            degrees[edges[i][1]]++; // updating how many edges each node has
            degrees[edges[i][0]]++; // updating how many edges each node has
        }
        queue<int>queue; // makes a queue of ints
        for(int i=0;i<n;i++) // loops for the number of nodes
        {
            if(degrees[i]==1) // checcks if the degrees at index i is 1 (if it it is a leaf)
                queue.push(i); // adds all the leave nodes
        }
        while(!queue.empty()) // loops while the queue is empty
        {
            res.clear(); // clear vector before we start traversing level by level
            int size=queue.size(); // set an int to the size of the queue 
            for(int i=0;i<size;i++) // loop for the size of the queue
            {
                int cur=queue.front(); // set an int to the value at the front of the queue
                queue.pop(); // pop a value from the queue
                res.push_back(cur); // pushses back the curr array to the answer array
                for(auto &neighbor:adj[cur]) // lops for values in adj at the current index
                {
                    degrees[neighbor]--; // removing current leave nodes by lowering the number of degrees
                    if(degrees[neighbor]==1) // check for leaf nodes after reducing the degrees
                        queue.push(neighbor); // pushes any leaves to the queue
                }
            }
        }
        return res; // return the answer array
    }
};