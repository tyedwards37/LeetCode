/* Daily Question: 1637. Widest Vertical Area Between Two Points Containing No Points
 * by Tyler Edwards | December 22nd, 2023 
 * Code Credit: lancertech6
 * Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. 
 * You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
 * Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise. */

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0}; 
        
        unordered_set<string> visited;
        visited.insert("0,0");
        
        int x = 0;
        int y = 0;
        
        for (char c : path) 
        {
            pair<int, int> curr = moves[c];
            int dx = curr.first;
            int dy = curr.second;
            
            x += dx;
            y += dy;
            
            string hash = to_string(x) + "," + to_string(y);
            
            if (visited.find(hash) != visited.end()) 
            {
                return true;
            }
            
            visited.insert(hash);
        }
        
        return false;
    }
};