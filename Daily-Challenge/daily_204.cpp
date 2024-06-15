/* Daily Question: 502. IPO
 * by Tyler Edwards | June 14th, 2024 
 * Code Credit: bhanu_bhakta
 * Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. 
 * Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
 * You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
 * Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
 * Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital. 
 * The answer is guaranteed to fit in a 32-bit signed integer. */

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects;

        // Creating vector of pairs (capital, profits)
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Sorting projects by capital required
        std::sort(projects.begin(), projects.end());

        // Max-heap to store profits, using greater to create a max-heap
        std::priority_queue<int> maxHeap;
        int i = 0;

        // Main loop to select up to k projects
        for (int j = 0; j < k; ++j) {
            // Add all profitable projects that we can afford
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // If no projects can be funded, break out of the loop
            if (maxHeap.empty()) {
                break;
            }

            // Otherwise, take the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};