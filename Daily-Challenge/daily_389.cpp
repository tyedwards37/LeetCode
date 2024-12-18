/* Daily Question: 1475. Final Prices With a Special Discount in a Shop
 * by Tyler Edwards | December 17th, 2024  
 * Code Credit: lee
 * You are given an integer array prices where prices[i] is the price of the ith item in a shop.
 * There is a special discount for items in the shop. 
 * If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. 
 * Otherwise, you will not receive any discount at all.
 * Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount. */

class Solution {
public:
    vector<int> finalPrices(vector<int>& A) {
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            while (stack.size() && A[stack.back()] >= A[i]) {
                A[stack.back()] -= A[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return A;
    }
};