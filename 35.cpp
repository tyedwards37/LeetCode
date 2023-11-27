/* LeetCode Day 33: Asteroid Collision (735) (Medium) 35/75 
 * by Tyler Edwards | November 26th, 2023 
 * We are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 * Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet. */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        stack<int> stack;

        for(int i = 0; i < n; i++)
        {
            if(asteroids[i] > 0 || stack.empty())
            {
                stack.push(asteroids[i]);
            }

            else
            {
                while (!stack.empty() && stack.top() > 0 && stack.top() < abs(asteroids[i]))
                {
                    stack.pop();
                }

                if (!stack.empty() &&  stack.top() == abs(asteroids[i]))
                {
                    stack.pop();
                }

                else
                {
                    if (stack.empty() || stack.top() < 0)
                    {
                        stack.push(asteroids[i]);
                    }
                }
            }
        }

        vector<int> answer(stack.size());
        for(int i = (int) stack.size() - 1; i >= 0; i--)
        {
            answer[i] = stack.top();
            stack.pop();
        }

        return answer;
    }
};