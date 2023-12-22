/* Daily Question: 1637. Widest Vertical Area Between Two Points Containing No Points
 * by Tyler Edwards | December 21st, 2023 
 * Code Credit: kaju-katli
 * Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
 * A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
 * Note that points on the edge of a vertical area are not considered included in the area. */

class Solution {
public:
    int maxScore(string s) 
    {
        int rightOnes = 0, leftZeroes = 0;
        for (char c : s)
        {
            if (c == '1')
            {
                rightOnes++;
            }
        }

        int total = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
            {
                leftZeroes++;
            }

            else
            {
                rightOnes--;
            }

            total = max(total, leftZeroes + rightOnes);
        }

        return total;
    }
};

