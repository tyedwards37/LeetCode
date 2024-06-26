/* Daily Question: 1052. Grumpy Bookstore Owner
 * by Tyler Edwards | June 20th, 2024
 * Code Credit: votrubac
 * There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. 
 * You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.
 * On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.
 * When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.
 * The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.
 * Return the maximum number of customers that can be satisfied throughout the day. */

class Solution {
public:
    int maxSatisfied(vector<int>& cs, vector<int>& grumpy, int X) {
        auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
        for (auto i = 0; i < cs.size(); ++i) {
            satisfied += !grumpy[i] * cs[i];
            add_satisfied += grumpy[i] * cs[i];
            if (i >= X) 
                add_satisfied -= grumpy[i - X] * cs[i - X];
            m_add_satisfied = max(m_add_satisfied, add_satisfied);
        }
        return satisfied + m_add_satisfied;
    }
};  