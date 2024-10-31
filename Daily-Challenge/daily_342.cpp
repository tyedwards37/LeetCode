/* Daily Question: 2463. Minimum Total Distance Traveled
 * by Tyler Edwards | October 30th, 2024 
 * Code Credit: tojuna
 * There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. 
 * You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.
 * The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.
 * All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. 
 * When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.
 * At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.
 * Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired. */

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort both robots and factories for optimal assignment
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m = robot.size(), n = factory.size();
        // dp[i][j]: minimum total distance for robots[i:] using factories[j:]
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        
        // Base case: if no factories are available, distance is infinity
        for (int i = 0; i < m; i++) {
            dp[i][n] = LLONG_MAX;
        }
        
        // Process each factory from right to left
        for (int j = n - 1; j >= 0; j--) {
            // Track cumulative distance from current factory to robots
            long long prefix = 0;
            // Deque stores pairs of (robot index, minimum distance)
            deque<pair<int, long long>> qq;
            // Initialize with base case
            qq.push_back({m, 0});
            
            // Process each robot from right to left
            for (int i = m - 1; i >= 0; i--) {
                // Add distance from current robot to current factory
                prefix += abs(robot[i] - factory[j][0]);
                
                // Remove entries that exceed factory capacity
                while (!qq.empty() && qq.front().first > i + factory[j][1]) {
                    qq.pop_front();
                }
                
                // Maintain monotonic property of deque
                while (!qq.empty() && qq.back().second >= dp[i][j + 1] - prefix) {
                    qq.pop_back();
                }
                
                // Add current state to deque
                qq.push_back({i, dp[i][j + 1] - prefix});
                // Calculate minimum distance for current state
                dp[i][j] = qq.front().second + prefix;
            }
        }
        
        // Return minimum total distance starting from first robot and first factory
        return dp[0][0];
    }
};