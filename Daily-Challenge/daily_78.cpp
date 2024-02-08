/* Daily Question: 279. Perfect Squares
 * by Tyler Edwards | February 7th, 2024 
 * Code Credit: RushRab
 * Given an integer n, return the least number of perfect square numbers that sum to n.
 * A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
 * For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not. */

class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        static vector<int> cntPerfectSquares({0});
        
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;

            for (int i = 1; i * i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};