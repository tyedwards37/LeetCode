/* Daily Question: 2751. Robot Collisions
 * by Tyler Edwards | July 12th, 2024 
 * Code Credit: Aditya00
 * There are n 1-indexed robots, each having a position on a line, health, and movement direction.
 * You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.
 * All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.
 * If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. 
 * The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.
 * Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. 
 * If there are no survivors, return an empty array.
 * Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur. */

class Solution {
public:

    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        int n = positions.size();
        vector<Robot> vals;
        for (int i = 0; i < n; i++) {
            vals.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(vals.begin(), vals.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        vector<Robot> stack;
        for (auto& robot : vals) {
            if (robot.direction == 'R') {
                stack.push_back(robot);
                continue;
            }

            // Check if the robot should be eliminated
            bool gone = false;

            // Process the stack to eliminate robots with lower health
            while (!stack.empty() && stack.back().health <= robot.health && stack.back().direction == 'R') {
                if (stack.back().health == robot.health) {
                    stack.pop_back();
                    gone = true;
                    break;
                }
                robot.health--;
                stack.pop_back();
            }

            // If the robot is not yet eliminated and there is a robot facing right with higher health
            if (!gone && !stack.empty() && stack.back().direction == 'R' && stack.back().health > robot.health) {
                stack.back().health--;
                gone = true;
            }

            // If the robot is not eliminated, add it to the stack
            if (!gone) {
                stack.push_back(robot);
            }
        }

        sort(stack.begin(), stack.end(), [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });

        vector<int> result;
        for (const auto& robot : stack) {
            result.push_back(robot.health);
        }

        return result;
    }
};