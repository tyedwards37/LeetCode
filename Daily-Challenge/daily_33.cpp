/* Daily Question: 1637. Widest Vertical Area Between Two Points Containing No Points
 * by Tyler Edwards | December 20th, 2023 
 * Code Credit: votrubac
 * Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
 * A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
 * Note that points on the edge of a vertical area are not considered included in the area. */

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        set<int> x;
        int res = 0;
        for (auto &p : points)
        {
            x.insert(p[0]);
        }

        for (auto it = next(begin(x)); it != end(x); ++it)
        {
            res = max(res, *it - *prev(it));
        }
        
        return res;
    }
};
