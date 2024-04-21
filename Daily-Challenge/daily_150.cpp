/* Daily Question: 1971. Find if Path Exists in Graph
 * by Tyler Edwards | April 20th, 2024 
 * Code Credit: aparna_g
 * There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
 * The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
 * Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
 * You want to determine if there is a valid path that exists from vertex source to vertex destination. 
 * Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise. */

 class Solution {
public:
    vector<int> parent;    // make a 2D array of ints to hold the parents 
    int findParent(int node) {
        return parent[node] == node ? node : (parent[node] = findParent(parent[node])); // if the parent node is equal to the given node then returnthe node if not set the parent  node equal to a recursive call to the find parent function
    }    

    void makeSameGroup(int u , int v) {
        int pu = findParent(u) ; // call find parent for the node at index u
        int pv = findParent(v); // call find parent for the node at index v
        parent[pu] = pv; // the parent of the call for index u is set to the call for index v
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        parent.resize(n); // sets the size of teh parent function to that of the given edge graph
        for(int i=0;i<n;i++) // loops for size of the graph 
            parent[i] = i; // sets the value at index i to the value of i 
        
        for(auto e : edges) { // loops through all the edges
            makeSameGroup(e[0] , e[1]); // call to make same group in the index for 0 and 1 to start the loop
        }                         
        return findParent(start) == findParent(end); // return if the number of the find parent start call is the same of find parent end call
    }
};
