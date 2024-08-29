/* Daily Question: 947. Most Stones Removed with Same Row or Column
 * by Tyler Edwards | August 28th, 2024 
 * Code Credit: pratyush63
 * On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
 * A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
 * Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed. */

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i)
            uni(stones[i][0], ~stones[i][1]);
        return stones.size() - islands;
    }

    unordered_map<int, int> f;
    int islands = 0;

    int find(int x) {
        if (!f.count(x)) f[x] = x, islands++;
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) f[x] = y, islands--;
    }
};