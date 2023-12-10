/* LeetCode Day 44: 841. Keys and Rooms (Medium) 48/75 
 * Tyler Edwards | December 9th, 2023 
 * Code Credit: zackchen95
 * There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
 * When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
 * Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise. */

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, unordered_set<int>& keys, unordered_set<int>& visited, int curr)
    {
        visited.insert(curr);
        for (int r : rooms[curr])
        {
            keys.insert(r);
        }

        for (int k : keys)
        {
            if (visited.find(k) == visited.end())
            {
                dfs(rooms, keys, visited, k);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        unordered_set<int> keys;
        unordered_set<int> visited;
        dfs(rooms, keys, visited, 0);
        return visited.size() == rooms.size();
    }
};