/* Daily Question: 874. Walking Robot Simulation
 * by Tyler Edwards | September 3rd, 2024 
 * Code Credit: MichaelZ
 * A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
 * - -2: Turn left 90 degrees.
 * - -1: Turn right 90 degrees.
 * - 1 <= k <= 9: Move forward k units, one unit at a time.
 * Some of the grid squares are obstacles. 
 * The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.
 * Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25). */

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for(int i=0;i<obstacles.size();i++) obs.insert(to_string(obstacles[i][0])+"#"+to_string(obstacles[i][1]));
        int res=0, dir=0, x=0, y=0;
        vector<vector<int>> ds={{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i=0;i<commands.size();i++) {
            if(commands[i]==-2) dir--;
            else if(commands[i]==-1) dir++;
            else {
                for(int j=0;j<commands[i];j++) {
                    string pos=to_string(x+ds[dir][0])+"#"+to_string(y+ds[dir][1]);
                    if(obs.find(pos)!=obs.end()) break;
                    x+=ds[dir][0], y+=ds[dir][1];
                }
                res=max(res, x*x+y*y);
            }
            if(dir==-1) dir=3;
            if(dir==4) dir=0;
        }
        return res;
    }
};