/* Daily Question: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * by Tyler Edwards | July 25th, 2024 
 * Code Credit: lee215
 * There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
 * Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
 * Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path. */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector(n, 10001));
        int res = 0, smallest = n;
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)
                    ++count;
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res;
    }
};