/* Daily Question: 752. Open the Lock
 * by Tyler Edwards | April 21st, 2024 
 * Code Credit: shtanriverdi
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
 * The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
 * The lock initially starts at '0000', a string representing the state of the 4 wheels.
 * You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
 * Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.*/

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        int result = 0;
        if (deadendsSet.find("0000") != deadendsSet.end()) {
            return -1;
        }
        queue<string> wheelQueue;
        wheelQueue.push("0000");
        visited.insert("0000");
        while (!wheelQueue.empty()) {
            int levelSize = wheelQueue.size();
            while (levelSize--) {
                string up, down, currentWheel = wheelQueue.front();
                wheelQueue.pop();
                if (currentWheel == target) {
                    return result;
                }
                for (int i = 0; i < 4; i++) {
                    down = up = currentWheel;
                    char upCh = up[i], downCh = down[i];
                    up[i] = (upCh == '9' ? '0' : upCh + 1);
                    down[i] = (downCh == '0' ? '9' : downCh - 1);
                    if (visited.find(up) == visited.end() && deadendsSet.find(up) == deadendsSet.end()) {
                        wheelQueue.push(up);
                        visited.insert(up);
                    }
                    if (visited.find(down) == visited.end() && deadendsSet.find(down) == deadendsSet.end()) {
                        wheelQueue.push(down);
                        visited.insert(down);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};