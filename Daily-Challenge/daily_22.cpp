/* Daily Question: 1716. Calculate Money in Leetcode Bank
 * by Tyler Edwards | December 5th, 2023 
 * Code Credit: lzl124631x
 * Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
 * He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
 * Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day. */

class Solution {
public:
    int totalMoney(int n) 
    {
       int answer = 0, week = 1;

       while (n > 0)
       {
           for (int i = 0; i < 7 && n-- > 0; ++i)
           {
               answer += week + i;
           }

           week++;
       }

       return answer;
    }
};
