/* LeetCode Beginner's Guide: 1672. Richest Customer Wealth (2/6)
 * by Tyler Edwards | January 14th, 2024 
 * You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
 * Return the wealth that the richest customer has.
 * A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth. */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;

        for (int i = 0; i < accounts.size(); i++) {
            int wealth = 0;

            for (int j = 0; j < accounts[0].size(); j++) {
                wealth += accounts[i][j];
            }

            maxWealth = max(maxWealth, wealth);
        }

        return maxWealth;
    }
};