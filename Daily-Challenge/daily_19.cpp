/* Daily Question: 1266. Minimum Time Visiting All Points
 * by Tyler Edwards | December 2nd, 2023 
 * On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.
 * You can move according to these rules:
 * - In 1 second, you can either:
 *      - move vertically by one unit,
 *      - move horizontally by one unit, or
 *      - move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
 * - You have to visit the points in the same order as they appear in the array.
 * - You are allowed to pass through points that appear later in the order, but these do not count as visits. */


class Solution {
public:
    int seconds = 0;

    void move(int x1, int y1, int x2, int y2)
    {
        int diffX = abs(x1 - x2), diffY = abs(y1 - y2);
        int maxDiff = max(diffX, diffY);
        
        while (maxDiff > 0)
        {
            if (diffX > 0)
            {
                diffX--;
            }

            if (diffY > 0)
            {
                diffY--;
            }

            seconds++;
            maxDiff--;
        }

        while (diffX != 0)
        {
            diffX--;
            seconds++;
        }

        while (diffY != 0)
        {
            diffY--;
            seconds++;
        }

        return;
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {

       for (int i = 0; i < points.size() - 1; i++)
       {
           move(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
       }

       return seconds;
    }
};
