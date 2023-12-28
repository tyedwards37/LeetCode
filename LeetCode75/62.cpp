/* LeetCode Day 56: 216. Combination Sum III (Medium) 62/75 
 * Tyler Edwards | December 27th, 2023 
 * Code Credit: yushu
 * Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 * - Only numbers 1 through 9 are used.
 * - Each number is used at most once.
 * Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order. */

class Solution {
public:
    void combination(vector<vector<int>>& answer, vector<int> sol, int k, int n)
    {
        if (sol.size() == k && n == 0)
        {
            answer.push_back(sol);
            return;
        }

        if (sol.size() < k)
        {
            for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; i++)
            {
                if (n - i < 0)
                {
                    break;
                }

                sol.push_back(i);
                combination(answer, sol, k, n - i);
                sol.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> answer;
        vector<int> sol;
        combination(answer, sol, k, n);
        return answer;
    }
};