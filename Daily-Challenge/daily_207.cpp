/* Daily Question: 826. Most Profit Assigning Work
 * by Tyler Edwards | June 17th, 2024 
 * Code Credit: moheat
 * You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
 * - difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
 * - worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
 * Every worker can be assigned at most one job, but one job can be completed multiple times.
 * - For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
 * Return the maximum profit we can achieve after assigning the workers to the jobs. */

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        sort(worker.begin(),worker.end());
        vector<pair<int,int>> nums(n);

        for(int i=0;i<n;i++)
        {
            nums[i] = {difficulty[i],profit[i]};
        }
        sort(nums.begin(),nums.end());

        int maxProfit = 0;
        int tempProfit = 0;
        for(int i=0,j=0;i<n;i++)
        {
            while(j<n && nums[j].first <= worker[i])
            {
                tempProfit = max(nums[j].second,tempProfit);
                j++;
            }
            if(j>0 && nums[j-1].first <= worker[i])
            {
                maxProfit = maxProfit + tempProfit;
            }
        }
        return maxProfit;
    }
};