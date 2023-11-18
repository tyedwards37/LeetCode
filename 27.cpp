/* LeetCode Day 25: Container with Most WAter (11) (Medium) 27/75 
 * by Tyler Edwards | November 18th, 2023 
 * Desc: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store. */

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int area = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int minSideHeight = min(height[i], height[j]);
            area = max(area, (j - i) * minSideHeight);
            while (height[i] <= minSideHeight && i < j) i++;
            while (height[j] <= minSideHeight && i < j) j--;
        }

        return area;
    }
};