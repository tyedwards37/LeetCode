/* Daily Question: 386. Lexicographical Numbers
 * by Tyler Edwards | September 20th, 2024 
 * Code Credit: withacup
 * Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space.  */

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return res;
    }
};