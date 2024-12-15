/* Daily Question: 1792. Maximum Average Pass Ratio
 * by Tyler Edwards | December 14th, 2024  
 * Code Credit: Piyush Jaiswal
 * There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. 
 * You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
 * You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. 
 * You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
 * The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. 
 * The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
 * Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted. */

 class Solution {
    public:
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            auto profit = [&](double pass, double total) {
                return (pass + 1) / (total + 1) - pass / total;
            };
            double total = 0;
            priority_queue<pair<double, array<int, 2>>> pq;
            for (auto &c : classes) {
                total += (double) c[0] / c[1];
                pq.push({profit(c[0], c[1]), {c[0], c[1]}});
            }
            while (extraStudents--) {
                auto [added_profit, c] = pq.top(); pq.pop();
                total += added_profit;
                pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
            }
            return total / classes.size();
        }
    };