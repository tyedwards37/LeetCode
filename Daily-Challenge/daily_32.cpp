/* Daily Question: 2706. Buy Two Chocolates
 * by Tyler Edwards | December 19th, 2023 
 * You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.
 * You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.
 * Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative. */

 class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        int budget = money;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (auto p : prices)
        {
            min2 = min(p, min2);

            if (p < min2)
            {
                min2 = p;
            }

            if (min2 < min1)
            {
                min2 = min1;
                min1 = p; 
            }
        }

        budget -= min1 + min2;

        if(budget < 0)
        {
            return money;
        }

        return budget;
    }
};