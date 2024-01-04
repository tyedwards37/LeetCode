/* LeetCode Day 61: 714. Best Time to Buy and Sell Stock with Transaction Fee (Medium) 67/75 
 * Tyler Edwards | January 3rd, 2024 
 * Code Credit: rahulvarma5297
 * You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
 * Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int buy = INT_MIN;
        int sell = 0;

        for (int price: prices)
        {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }

        return sell;
    }
};